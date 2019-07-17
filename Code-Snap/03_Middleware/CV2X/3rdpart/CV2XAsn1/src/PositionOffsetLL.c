/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "DefPositionOffset"
 * 	found in "DefPositionOffset.asn"
 */

#include "PositionOffsetLL.h"

static asn_TYPE_member_t asn_MBR_PositionOffsetLL_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL1),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_24B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL1"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL2),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_28B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL2"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL3),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_32B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL3"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL4),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_36B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL4"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL5),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_44B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL5"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LL6),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LL_48B,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LL6"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PositionOffsetLL, choice.position_LatLon),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position_LLmD_64b,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"position-LatLon"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_PositionOffsetLL_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* position-LL1 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* position-LL2 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* position-LL3 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* position-LL4 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* position-LL5 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* position-LL6 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* position-LatLon */
};
static asn_CHOICE_specifics_t asn_SPC_PositionOffsetLL_specs_1 = {
	sizeof(struct PositionOffsetLL),
	offsetof(struct PositionOffsetLL, _asn_ctx),
	offsetof(struct PositionOffsetLL, present),
	sizeof(((struct PositionOffsetLL *)0)->present),
	asn_MAP_PositionOffsetLL_tag2el_1,
	7,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_PositionOffsetLL = {
	"PositionOffsetLL",
	"PositionOffsetLL",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_PositionOffsetLL_1,
	7,	/* Elements count */
	&asn_SPC_PositionOffsetLL_specs_1	/* Additional specs */
};

