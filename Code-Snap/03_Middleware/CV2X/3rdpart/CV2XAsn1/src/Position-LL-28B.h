/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "DefPositionOffset"
 * 	found in "DefPositionOffset.asn"
 */

#ifndef	_Position_LL_28B_H_
#define	_Position_LL_28B_H_


#include <asn_application.h>

/* Including external dependencies */
#include "OffsetLL-B14.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Position-LL-28B */
typedef struct Position_LL_28B {
	OffsetLL_B14_t	 lon;
	OffsetLL_B14_t	 lat;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Position_LL_28B_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Position_LL_28B;

#ifdef __cplusplus
}
#endif

#endif	/* _Position_LL_28B_H_ */
#include <asn_internal.h>