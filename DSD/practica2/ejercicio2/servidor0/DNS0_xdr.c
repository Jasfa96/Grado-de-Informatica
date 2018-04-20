/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "DNS0.h"

bool_t
xdr_nombre (XDR *xdrs, nombre *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, TAM))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_red (XDR *xdrs, red *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, TAM))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ip (XDR *xdrs, ip *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, TAM))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_introducir_1_argument (XDR *xdrs, introducir_1_argument *objp)
{
	 if (!xdr_nombre (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_red (xdrs, &objp->arg2))
		 return FALSE;
	 if (!xdr_ip (xdrs, &objp->arg3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_eliminar_1_argument (XDR *xdrs, eliminar_1_argument *objp)
{
	 if (!xdr_nombre (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_red (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_consultar_1_argument (XDR *xdrs, consultar_1_argument *objp)
{
	 if (!xdr_nombre (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_red (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}