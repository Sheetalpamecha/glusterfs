#!/bin/bash

. $(dirname $0)/../../include.rc
. $(dirname $0)/../../volume.rc

cleanup

function num_entries {
	ls $1 | wc -l
}

TEST glusterd
TEST pidof glusterd
TEST $CLI volume create $V0 disperse 3 redundancy 1 $H0:$B0/${V0}{0..2}
TEST $CLI volume set $V0 performance.quick-read off
TEST $CLI volume set $V0 performance.io-cache off
TEST $CLI volume set $V0 performance.write-behind off
TEST $CLI volume set $V0 performance.stat-prefetch off
TEST $CLI volume set $V0 performance.read-ahead off
TEST $CLI volume set $V0 performance.open-behind off
TEST $CLI volume start $V0
TEST $CLI volume heal $V0 disable
TEST $CLI volume set $V0 disperse.use-anonymous-inode on
TEST $CLI volume set $V0 cluster.heal-timeout 60

TEST $GFS --volfile-id=/$V0 --volfile-server=$H0 $M0

TEST touch $M0/f1
TEST touch $M0/f2

TEST `echo "I am F1" >> $M0/f1`
TEST `echo "I am F2" >> $M0/f2`

gfid_f1=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/f1))
gfid_f2=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/f2))

TEST kill_brick $V0 $H0 $B0/${V0}0
EXPECT_WITHIN $CHILD_UP_TIMEOUT "2" ec_child_up_count $V0 0
TEST mv $M0/f2 $M0/f1

TEST $CLI volume start $V0 force
EXPECT_WITHIN $CHILD_UP_TIMEOUT "3" ec_child_up_count $V0 0
TEST ! ls $M0/f2

anon_inode_name=$(ls -a $B0/${V0}0 | grep glusterfs-anonymous-inode)
TEST stat $B0/${V0}0/$anon_inode_name/$gfid_f2
TEST rm -f $B0/${V0}1/.glusterfs/indices/xattrop/*
TEST rm -f $B0/${V0}2/.glusterfs/indices/xattrop/*

TEST $CLI volume heal $V0 enable
EXPECT_WITHIN $PROCESS_UP_TIMEOUT "Y" glustershd_up_status

TEST $CLI volume heal $V0
EXPECT_WITHIN $HEAL_TIMEOUT "^0$" get_pending_heal_count $V0
sleep 5

TEST stat $B0/${V0}0/$anon_inode_name/$gfid_f2

TEST ! stat $M0/f2
TEST stat $M0/f1
EXPECT "I am F2" tail -1 $M0/f1

#Entry in /.glusterfs-anonymous-inode dir will be created only on those bricks
#which were down at the time of rename
EXPECT "^1$" num_entries $B0/${V0}0/$anon_inode_name/

TEST mkdir -p $M0/d1/b $M0/d2/a
TEST kill_brick $V0 $H0 $B0/${V0}0
TEST mv $M0/d2/a $M0/d1
TEST mv $M0/d1/b $M0/d2
TEST $CLI volume start $V0 force

#Successful creation of /.glusterfs-anonymous-inode on all bricks
hidden_dir=$(ls -a $B0/${V0}0 | grep glusterfs-anonymous-inode)
TEST [[ -d $B0/${V0}1/$hidden_dir ]]
TEST [[ -d $B0/${V0}2/$hidden_dir ]]

hidden_dir_gfid=$(gf_get_gfid_xattr $B0/${V0}0/$hidden_dir)
EXPECT "$hidden_dir_gfid" gf_get_gfid_xattr $B0/${V0}1/$hidden_dir
EXPECT "$hidden_dir_gfid" gf_get_gfid_xattr $B0/${V0}2/$hidden_dir

TEST $CLI volume heal $V0 disable
TEST $CLI volume start $V0 force
EXPECT_WITHIN $CHILD_UP_TIMEOUT "3" ec_child_up_count $V0 0

TEST mkdir $M0/l0 $M0/l1 $M0/l2
TEST touch $M0/del-file $M0/del-file-nolink $M0/l0/file
TEST ln $M0/del-file $M0/del-file-link
TEST ln $M0/l0/file $M0/l1/file-link1
TEST ln $M0/l0/file $M0/l2/file-link2
TEST mkdir -p $M0/del-recursive-dir/d1

TEST kill_brick $V0 $H0 $B0/${V0}0
TEST rm -f $M0/del-file $M0/del-file-nolink
TEST rm -rf $M0/del-recursive-dir
TEST mv $M0/d1/a $M0/d2
TEST mv $M0/l0/file $M0/l0/renamed-file

nolink_gfid=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/del-file-nolink))
link_gfid=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/del-file))
dir_gfid=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/del-recursive-dir))
rename_file_gfid=$(gf_gfid_xattr_to_str $(gf_get_gfid_xattr $B0/${V0}0/l0/file))

TEST $CLI volume start $V0 force
EXPECT_WITHIN $CHILD_UP_TIMEOUT "3" ec_child_up_count $V0 0

TEST ! stat $M0/del-file
TEST stat $B0/${V0}0/$hidden_dir/$link_gfid
TEST ! stat $M0/del-file-nolink
TEST ! stat $B0/${V0}0/$hidden_dir/$nolink_gfid
TEST ! stat $M0/del-recursive-dir
TEST ! stat $B0/${V0}0/$hidden_dir/$dir_gfid
TEST ! stat $M0/d1/a
TEST ! stat $M0/l0/file
TEST ! stat $B0/${V0}0/$hidden_dir/$rename_file_gfid

TEST kill_brick $V0 $H0 $B0/${V0}1
TEST $CLI volume start $V0 force
EXPECT_WITHIN $CHILD_UP_TIMEOUT "3" ec_child_up_count $V0 0
TEST stat $M0/l1/file-link1
TEST ! stat $B0/${V0}1/$hidden_dir/$rename_file_gfid

#Simulate only anon-inodes present in all bricks
TEST rm -f $M0/l0/renamed-file $M0/l1/renamed-file-link1 $M0/l2/renamed-file-link2

#Test that shd doesn't cleanup anon-inodes when some bricks are down
TEST kill_brick $V0 $H0 $B0/${V0}1
TEST $CLI volume heal $V0 enable
TEST $CLI volume heal $V0
sleep 5 #Allow time for completion of one scan
TEST stat $B0/${V0}0/$hidden_dir/$link_gfid
TEST stat $B0/${V0}0/$hidden_dir/$rename_dir_gfid
TEST ! stat $B0/${V0}0/$hidden_dir/$dir_gfid

TEST $CLI volume start $V0 force
EXPECT_WITHIN $CHILD_UP_TIMEOUT "3" ec_child_up_count $V0 0

cleanup

