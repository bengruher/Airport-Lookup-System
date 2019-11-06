/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "ClientToPlaces.h"

bool_t
xdr_places (XDR *xdrs, places *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->code, 4))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, 64))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->state, 3))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->dist))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (places), (xdrproc_t) xdr_places))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_city (XDR *xdrs, city *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->state, 3))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->city, 64))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_returnTypeC (XDR *xdrs, returnTypeC *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->err))
		 return FALSE;
	switch (objp->err) {
	case 0:
		 if (!xdr_pointer (xdrs, (char **)&objp->returnTypeC_u.resultC, sizeof (places), (xdrproc_t) xdr_places))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}
