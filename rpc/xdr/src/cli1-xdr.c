/*
  Copyright (c) 2007-2011 Gluster, Inc. <http://www.gluster.com>
  This file is part of GlusterFS.

  GlusterFS is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.

  GlusterFS is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.
*/

#include "xdr-common.h"

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "cli1-xdr.h"

bool_t
xdr_gf_cli_defrag_type (XDR *xdrs, gf_cli_defrag_type *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cluster_type (XDR *xdrs, gf1_cluster_type *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_replace_op (XDR *xdrs, gf1_cli_replace_op *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf_quota_type (XDR *xdrs, gf_quota_type *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_friends_list (XDR *xdrs, gf1_cli_friends_list *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_get_volume (XDR *xdrs, gf1_cli_get_volume *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_sync_volume (XDR *xdrs, gf1_cli_sync_volume *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_op_flags (XDR *xdrs, gf1_cli_op_flags *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_gsync_set (XDR *xdrs, gf1_cli_gsync_set *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_stats_op (XDR *xdrs, gf1_cli_stats_op *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_top_op (XDR *xdrs, gf1_cli_top_op *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_probe_req (XDR *xdrs, gf1_cli_probe_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->hostname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->port))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_probe_rsp (XDR *xdrs, gf1_cli_probe_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->port))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->op_ret);
		IXDR_PUT_LONG(buf, objp->op_errno);
		IXDR_PUT_LONG(buf, objp->port);
		}
		 if (!xdr_string (xdrs, &objp->hostname, ~0))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->op_ret))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->op_errno))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->port))
				 return FALSE;

		} else {
		objp->op_ret = IXDR_GET_LONG(buf);
		objp->op_errno = IXDR_GET_LONG(buf);
		objp->port = IXDR_GET_LONG(buf);
		}
		 if (!xdr_string (xdrs, &objp->hostname, ~0))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->port))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->hostname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_deprobe_req (XDR *xdrs, gf1_cli_deprobe_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->hostname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->port))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_deprobe_rsp (XDR *xdrs, gf1_cli_deprobe_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->hostname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_peer_list_req (XDR *xdrs, gf1_cli_peer_list_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_peer_list_rsp (XDR *xdrs, gf1_cli_peer_list_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->friends.friends_val, (u_int *) &objp->friends.friends_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_get_vol_req (XDR *xdrs, gf1_cli_get_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_get_vol_rsp (XDR *xdrs, gf1_cli_get_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->volumes.volumes_val, (u_int *) &objp->volumes.volumes_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_create_vol_req (XDR *xdrs, gf1_cli_create_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_gf1_cluster_type (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->count))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->bricks.bricks_val, (u_int *) &objp->bricks.bricks_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_create_vol_rsp (XDR *xdrs, gf1_cli_create_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_delete_vol_req (XDR *xdrs, gf1_cli_delete_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_delete_vol_rsp (XDR *xdrs, gf1_cli_delete_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_start_vol_req (XDR *xdrs, gf1_cli_start_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_start_vol_rsp (XDR *xdrs, gf1_cli_start_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_stop_vol_req (XDR *xdrs, gf1_cli_stop_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_stop_vol_rsp (XDR *xdrs, gf1_cli_stop_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_rename_vol_req (XDR *xdrs, gf1_cli_rename_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->old_volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->new_volname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_rename_vol_rsp (XDR *xdrs, gf1_cli_rename_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_defrag_vol_req (XDR *xdrs, gf1_cli_defrag_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->cmd))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_defrag_vol_rsp (XDR *xdrs, gf1_cli_defrag_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->files))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->lookedup_files))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf2_cli_defrag_vol_rsp (XDR *xdrs, gf2_cli_defrag_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->files))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_u_quad_t (xdrs, &objp->lookedup_files))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_add_brick_req (XDR *xdrs, gf1_cli_add_brick_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->count))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->bricks.bricks_val, (u_int *) &objp->bricks.bricks_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_add_brick_rsp (XDR *xdrs, gf1_cli_add_brick_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_remove_brick_req (XDR *xdrs, gf1_cli_remove_brick_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->count))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->bricks.bricks_val, (u_int *) &objp->bricks.bricks_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_remove_brick_rsp (XDR *xdrs, gf1_cli_remove_brick_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_replace_brick_req (XDR *xdrs, gf1_cli_replace_brick_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_gf1_cli_replace_op (xdrs, &objp->op))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->bricks.bricks_val, (u_int *) &objp->bricks.bricks_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_replace_brick_rsp (XDR *xdrs, gf1_cli_replace_brick_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->status, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_reset_vol_req (XDR *xdrs, gf1_cli_reset_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_reset_vol_rsp (XDR *xdrs, gf1_cli_reset_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_set_vol_req (XDR *xdrs, gf1_cli_set_vol_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_set_vol_rsp (XDR *xdrs, gf1_cli_set_vol_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_filename_req (XDR *xdrs, gf1_cli_log_filename_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->brick, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_filename_rsp (XDR *xdrs, gf1_cli_log_filename_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_locate_req (XDR *xdrs, gf1_cli_log_locate_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->brick, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_sync_volume_req (XDR *xdrs, gf1_cli_sync_volume_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->flags))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->hostname, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_locate_rsp (XDR *xdrs, gf1_cli_log_locate_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->path, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_rotate_req (XDR *xdrs, gf1_cli_log_rotate_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->brick, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_rotate_rsp (XDR *xdrs, gf1_cli_log_rotate_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_sync_volume_rsp (XDR *xdrs, gf1_cli_sync_volume_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_fsm_log_req (XDR *xdrs, gf1_cli_fsm_log_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_fsm_log_rsp (XDR *xdrs, gf1_cli_fsm_log_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->fsm_log.fsm_log_val, (u_int *) &objp->fsm_log.fsm_log_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_gsync_set_req (XDR *xdrs, gf1_cli_gsync_set_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_gsync_set_rsp (XDR *xdrs, gf1_cli_gsync_set_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_stats_volume_req (XDR *xdrs, gf1_cli_stats_volume_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_gf1_cli_stats_op (xdrs, &objp->op))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict_req.dict_req_val, (u_int *) &objp->dict_req.dict_req_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_stats_volume_rsp (XDR *xdrs, gf1_cli_stats_volume_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->stats_info.stats_info_val, (u_int *) &objp->stats_info.stats_info_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_quota_req (XDR *xdrs, gf1_cli_quota_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_quota_rsp (XDR *xdrs, gf1_cli_quota_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->limit_list, ~0))
		 return FALSE;
	 if (!xdr_gf_quota_type (xdrs, &objp->type))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_getwd_req (XDR *xdrs, gf1_cli_getwd_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->unused))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_getwd_rsp (XDR *xdrs, gf1_cli_getwd_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->wd, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_level_req (XDR *xdrs, gf1_cli_log_level_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->xlator, ~0))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->loglevel, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_log_level_rsp (XDR *xdrs, gf1_cli_log_level_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_status_volume_req (XDR *xdrs, gf1_cli_status_volume_req *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_string (xdrs, &objp->volname, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gf1_cli_status_volume_rsp (XDR *xdrs, gf1_cli_status_volume_rsp *objp)
{
	register int32_t *buf;
        buf = NULL;

	 if (!xdr_int (xdrs, &objp->op_ret))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->op_errno))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->op_errstr, ~0))
		 return FALSE;
	 if (!xdr_bytes (xdrs, (char **)&objp->dict.dict_val, (u_int *) &objp->dict.dict_len, ~0))
		 return FALSE;
	return TRUE;
}
