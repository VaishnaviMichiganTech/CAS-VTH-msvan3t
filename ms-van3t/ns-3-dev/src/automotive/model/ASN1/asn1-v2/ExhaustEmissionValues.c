/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_14906_EfcDsrcApplication.asn"
 * 	`asn1c -fincludes-quoted`
 */

#include "ExhaustEmissionValues.h"

static int
memb_emissionCO_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 32767)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_emissionCO_constr_3 CC_NOTUSED = {
	{ 2, 1 }	/* (0..32767) */,
	-1};
static asn_per_constraints_t asn_PER_memb_emissionCO_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 15,  15,  0,  32767 }	/* (0..32767) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_ExhaustEmissionValues_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ExhaustEmissionValues, unitType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UnitType,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"unitType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ExhaustEmissionValues, emissionCO),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_emissionCO_constr_3, &asn_PER_memb_emissionCO_constr_3,  memb_emissionCO_constraint_1 },
		0, 0, /* No default value */
		"emissionCO"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ExhaustEmissionValues, emissionHC),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Int2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"emissionHC"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ExhaustEmissionValues, emissionNOX),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Int2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"emissionNOX"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ExhaustEmissionValues, emissionHCNOX),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Int2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"emissionHCNOX"
		},
};
static const ber_tlv_tag_t asn_DEF_ExhaustEmissionValues_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ExhaustEmissionValues_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* unitType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* emissionCO */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* emissionHC */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* emissionNOX */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* emissionHCNOX */
};
asn_SEQUENCE_specifics_t asn_SPC_ExhaustEmissionValues_specs_1 = {
	sizeof(struct ExhaustEmissionValues),
	offsetof(struct ExhaustEmissionValues, _asn_ctx),
	asn_MAP_ExhaustEmissionValues_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ExhaustEmissionValues = {
	"ExhaustEmissionValues",
	"ExhaustEmissionValues",
	&asn_OP_SEQUENCE,
	asn_DEF_ExhaustEmissionValues_tags_1,
	sizeof(asn_DEF_ExhaustEmissionValues_tags_1)
		/sizeof(asn_DEF_ExhaustEmissionValues_tags_1[0]), /* 1 */
	asn_DEF_ExhaustEmissionValues_tags_1,	/* Same as above */
	sizeof(asn_DEF_ExhaustEmissionValues_tags_1)
		/sizeof(asn_DEF_ExhaustEmissionValues_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ExhaustEmissionValues_1,
	5,	/* Elements count */
	&asn_SPC_ExhaustEmissionValues_specs_1	/* Additional specs */
};
