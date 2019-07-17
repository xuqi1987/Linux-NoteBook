/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "VehBrake"
 * 	found in "VehBrake.asn"
 */

#ifndef	_BrakeBoostApplied_H_
#define	_BrakeBoostApplied_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum BrakeBoostApplied {
	BrakeBoostApplied_unavailable	= 0,
	BrakeBoostApplied_off	= 1,
	BrakeBoostApplied_on	= 2
} e_BrakeBoostApplied;

/* BrakeBoostApplied */
typedef long	 BrakeBoostApplied_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BrakeBoostApplied;
asn_struct_free_f BrakeBoostApplied_free;
asn_struct_print_f BrakeBoostApplied_print;
asn_constr_check_f BrakeBoostApplied_constraint;
ber_type_decoder_f BrakeBoostApplied_decode_ber;
der_type_encoder_f BrakeBoostApplied_encode_der;
xer_type_decoder_f BrakeBoostApplied_decode_xer;
xer_type_encoder_f BrakeBoostApplied_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _BrakeBoostApplied_H_ */
#include <asn_internal.h>
