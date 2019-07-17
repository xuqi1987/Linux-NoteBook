/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "MapLink"
 * 	found in "MapLink.asn"
 */

#ifndef	_MovementList_H_
#define	_MovementList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Movement;

/* MovementList */
typedef struct MovementList {
	A_SEQUENCE_OF(struct Movement) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MovementList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MovementList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Movement.h"

#endif	/* _MovementList_H_ */
#include <asn_internal.h>
