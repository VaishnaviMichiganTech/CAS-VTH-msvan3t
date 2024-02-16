/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_14906_EfcDsrcApplication.asn"
 * 	`asn1c -fincludes-quoted`
 */

#include "PassengerCapacity.h"

asn_TYPE_member_t asn_MBR_PassengerCapacity_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PassengerCapacity, numberOfSeats),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Int1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"numberOfSeats"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PassengerCapacity, numberOfStandingPlaces),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Int1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"numberOfStandingPlaces"
		},
};
static const ber_tlv_tag_t asn_DEF_PassengerCapacity_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PassengerCapacity_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* numberOfSeats */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* numberOfStandingPlaces */
};
asn_SEQUENCE_specifics_t asn_SPC_PassengerCapacity_specs_1 = {
	sizeof(struct PassengerCapacity),
	offsetof(struct PassengerCapacity, _asn_ctx),
	asn_MAP_PassengerCapacity_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PassengerCapacity = {
	"PassengerCapacity",
	"PassengerCapacity",
	&asn_OP_SEQUENCE,
	asn_DEF_PassengerCapacity_tags_1,
	sizeof(asn_DEF_PassengerCapacity_tags_1)
		/sizeof(asn_DEF_PassengerCapacity_tags_1[0]), /* 1 */
	asn_DEF_PassengerCapacity_tags_1,	/* Same as above */
	sizeof(asn_DEF_PassengerCapacity_tags_1)
		/sizeof(asn_DEF_PassengerCapacity_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PassengerCapacity_1,
	2,	/* Elements count */
	&asn_SPC_PassengerCapacity_specs_1	/* Additional specs */
};

