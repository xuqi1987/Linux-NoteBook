/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "SPATIntersectionState"
 * 	found in "SPATIntersectionState.asn"
 */

#include "TimeChangeDetails.h"

static asn_TYPE_member_t asn_MBR_TimeChangeDetails_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TimeChangeDetails, startTime),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"startTime"
		},
	{ ATF_POINTER, 2, offsetof(struct TimeChangeDetails, minEndTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"minEndTime"
		},
	{ ATF_POINTER, 1, offsetof(struct TimeChangeDetails, maxEndTime),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"maxEndTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TimeChangeDetails, likelyEndTime),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"likelyEndTime"
		},
	{ ATF_POINTER, 3, offsetof(struct TimeChangeDetails, timeConfidence),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Confidence,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"timeConfidence"
		},
	{ ATF_POINTER, 2, offsetof(struct TimeChangeDetails, nextStartTime),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nextStartTime"
		},
	{ ATF_POINTER, 1, offsetof(struct TimeChangeDetails, nextDuration),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimeMark,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nextDuration"
		},
};
static const ber_tlv_tag_t asn_DEF_TimeChangeDetails_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TimeChangeDetails_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* startTime */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* minEndTime */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* maxEndTime */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* likelyEndTime */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* timeConfidence */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* nextStartTime */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* nextDuration */
};
static asn_SEQUENCE_specifics_t asn_SPC_TimeChangeDetails_specs_1 = {
	sizeof(struct TimeChangeDetails),
	offsetof(struct TimeChangeDetails, _asn_ctx),
	asn_MAP_TimeChangeDetails_tag2el_1,
	7,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_TimeChangeDetails = {
	"TimeChangeDetails",
	"TimeChangeDetails",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_TimeChangeDetails_tags_1,
	sizeof(asn_DEF_TimeChangeDetails_tags_1)
		/sizeof(asn_DEF_TimeChangeDetails_tags_1[0]), /* 1 */
	asn_DEF_TimeChangeDetails_tags_1,	/* Same as above */
	sizeof(asn_DEF_TimeChangeDetails_tags_1)
		/sizeof(asn_DEF_TimeChangeDetails_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_TimeChangeDetails_1,
	7,	/* Elements count */
	&asn_SPC_TimeChangeDetails_specs_1	/* Additional specs */
};
