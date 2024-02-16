/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/ISO-TS-19091.asn"
 * 	`asn1c -fincludes-quoted`
 */

#include "PositionConfidence.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_PositionConfidence_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_PositionConfidence_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_PositionConfidence_value2enum_1[] = {
	{ 0,	11,	"unavailable" },
	{ 1,	5,	"a500m" },
	{ 2,	5,	"a200m" },
	{ 3,	5,	"a100m" },
	{ 4,	4,	"a50m" },
	{ 5,	4,	"a20m" },
	{ 6,	4,	"a10m" },
	{ 7,	3,	"a5m" },
	{ 8,	3,	"a2m" },
	{ 9,	3,	"a1m" },
	{ 10,	5,	"a50cm" },
	{ 11,	5,	"a20cm" },
	{ 12,	5,	"a10cm" },
	{ 13,	4,	"a5cm" },
	{ 14,	4,	"a2cm" },
	{ 15,	4,	"a1cm" }
};
static const unsigned int asn_MAP_PositionConfidence_enum2value_1[] = {
	3,	/* a100m(3) */
	12,	/* a10cm(12) */
	6,	/* a10m(6) */
	15,	/* a1cm(15) */
	9,	/* a1m(9) */
	2,	/* a200m(2) */
	11,	/* a20cm(11) */
	5,	/* a20m(5) */
	14,	/* a2cm(14) */
	8,	/* a2m(8) */
	1,	/* a500m(1) */
	10,	/* a50cm(10) */
	4,	/* a50m(4) */
	13,	/* a5cm(13) */
	7,	/* a5m(7) */
	0	/* unavailable(0) */
};
const asn_INTEGER_specifics_t asn_SPC_PositionConfidence_specs_1 = {
	asn_MAP_PositionConfidence_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_PositionConfidence_enum2value_1,	/* N => "tag"; sorted by N */
	16,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_PositionConfidence_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_PositionConfidence = {
	"PositionConfidence",
	"PositionConfidence",
	&asn_OP_NativeEnumerated,
	asn_DEF_PositionConfidence_tags_1,
	sizeof(asn_DEF_PositionConfidence_tags_1)
		/sizeof(asn_DEF_PositionConfidence_tags_1[0]), /* 1 */
	asn_DEF_PositionConfidence_tags_1,	/* Same as above */
	sizeof(asn_DEF_PositionConfidence_tags_1)
		/sizeof(asn_DEF_PositionConfidence_tags_1[0]), /* 1 */
	{ &asn_OER_type_PositionConfidence_constr_1, &asn_PER_type_PositionConfidence_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_PositionConfidence_specs_1	/* Additional specs */
};

