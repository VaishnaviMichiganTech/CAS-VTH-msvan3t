/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CITSapplMgmtIDs"
 * 	found in "ASN1Files/ISO_TS_17419.asn"
 * 	`asn1c -fincludes-quoted`
 */

#include "VarLengthNumber.h"

static int
memb_content_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 127)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_content_constr_2 CC_NOTUSED = {
	{ 1, 1 }	/* (0..127) */,
	-1};
static asn_per_constraints_t asn_PER_memb_content_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_VarLengthNumber_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_VarLengthNumber_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_VarLengthNumber_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VarLengthNumber, choice.content),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_content_constr_2, &asn_PER_memb_content_constr_2,  memb_content_constraint_1 },
		0, 0, /* No default value */
		"content"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VarLengthNumber, choice.extension),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_Ext1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"extension"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_VarLengthNumber_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* content */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* extension */
};
asn_CHOICE_specifics_t asn_SPC_VarLengthNumber_specs_1 = {
	sizeof(struct VarLengthNumber),
	offsetof(struct VarLengthNumber, _asn_ctx),
	offsetof(struct VarLengthNumber, present),
	sizeof(((struct VarLengthNumber *)0)->present),
	asn_MAP_VarLengthNumber_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_VarLengthNumber = {
	"VarLengthNumber",
	"VarLengthNumber",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_VarLengthNumber_constr_1, &asn_PER_type_VarLengthNumber_constr_1, CHOICE_constraint },
	asn_MBR_VarLengthNumber_1,
	2,	/* Elements count */
	&asn_SPC_VarLengthNumber_specs_1	/* Additional specs */
};

