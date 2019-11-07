/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLIENTTOPLACES_H_RPCGEN
#define _CLIENTTOPLACES_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

extern char* places2k;

struct places {
	char code[4];
	char name[64];
	char state[3];
	double dist;
	double lat;
	double lon;
	struct places *next;
};
typedef struct places places;

struct city {
	char state[3];
	char city[64];
};
typedef struct city city;

struct returnTypeC {
	int err;
	union {
		places *resultC;
	} returnTypeC_u;
};
typedef struct returnTypeC returnTypeC;

#define CLIENT_TO_PLACES 0x23465879
#define CLIENT_TO_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define CToP 1
extern  returnTypeC * ctop_1(city *, CLIENT *);
extern  returnTypeC * ctop_1_svc(city *, struct svc_req *);
extern int client_to_places_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define CToP 1
extern  returnTypeC * ctop_1();
extern  returnTypeC * ctop_1_svc();
extern int client_to_places_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_places (XDR *, places*);
extern  bool_t xdr_city (XDR *, city*);
extern  bool_t xdr_returnTypeC (XDR *, returnTypeC*);

#else /* K&R C */
extern bool_t xdr_places ();
extern bool_t xdr_city ();
extern bool_t xdr_returnTypeC ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLIENTTOPLACES_H_RPCGEN */
