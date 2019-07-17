/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "MsgFrame"
 * 	found in "MsgFrame.asn"
 */

#ifndef	_MessageFrame_H_
#define	_MessageFrame_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BasicSafetyMessage.h"
#include "MapData.h"
#include "RoadsideSafetyMessage.h"
#include "SPAT.h"
#include "RoadSideInformation.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MessageFrame_PR {
	MessageFrame_PR_NOTHING,	/* No components present */
	MessageFrame_PR_bsmFrame,
	MessageFrame_PR_mapFrame,
	MessageFrame_PR_rsmFrame,
	MessageFrame_PR_spatFrame,
	MessageFrame_PR_rsiFrame,
	/* Extensions may appear below */
	
} MessageFrame_PR;

/* MessageFrame */
typedef struct MessageFrame {
	MessageFrame_PR present;
	union MessageFrame_u {
		BasicSafetyMessage_t	 bsmFrame;
		MapData_t	 mapFrame;
		RoadsideSafetyMessage_t	 rsmFrame;
		SPAT_t	 spatFrame;
		RoadSideInformation_t	 rsiFrame;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MessageFrame_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageFrame;

#ifdef __cplusplus
}
#endif

#endif	/* _MessageFrame_H_ */
#include <asn_internal.h>
