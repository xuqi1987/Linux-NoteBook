/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RSM"
 * 	found in "RSM.asn"
 */

#include "RoadsideSafetyMessage.h"

static int
memb_id_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 8)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_TYPE_member_t asn_MBR_RoadsideSafetyMessage_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RoadsideSafetyMessage, msgCnt),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MsgCount,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"msgCnt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RoadsideSafetyMessage, id),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_id_constraint_1,
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RoadsideSafetyMessage, refPos),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3D,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"refPos"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RoadsideSafetyMessage, participants),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ParticipantList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"participants"
		},
};
static const ber_tlv_tag_t asn_DEF_RoadsideSafetyMessage_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RoadsideSafetyMessage_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* msgCnt */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* refPos */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* participants */
};
static asn_SEQUENCE_specifics_t asn_SPC_RoadsideSafetyMessage_specs_1 = {
	sizeof(struct RoadsideSafetyMessage),
	offsetof(struct RoadsideSafetyMessage, _asn_ctx),
	asn_MAP_RoadsideSafetyMessage_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	3,	/* Start extensions */
	5	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RoadsideSafetyMessage = {
	"RoadsideSafetyMessage",
	"RoadsideSafetyMessage",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RoadsideSafetyMessage_tags_1,
	sizeof(asn_DEF_RoadsideSafetyMessage_tags_1)
		/sizeof(asn_DEF_RoadsideSafetyMessage_tags_1[0]), /* 1 */
	asn_DEF_RoadsideSafetyMessage_tags_1,	/* Same as above */
	sizeof(asn_DEF_RoadsideSafetyMessage_tags_1)
		/sizeof(asn_DEF_RoadsideSafetyMessage_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RoadsideSafetyMessage_1,
	4,	/* Elements count */
	&asn_SPC_RoadsideSafetyMessage_specs_1	/* Additional specs */
};

