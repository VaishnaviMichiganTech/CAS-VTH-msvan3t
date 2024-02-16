/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_19321_IVI.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_DeltaPosition_H_
#define	_DeltaPosition_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DeltaLatitude.h"
#include "DeltaLongitude.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* DeltaPosition */
typedef struct DeltaPosition {
	DeltaLatitude_t	 deltaLatitude;
	DeltaLongitude_t	 deltaLongitude;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DeltaPosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DeltaPosition;
extern asn_SEQUENCE_specifics_t asn_SPC_DeltaPosition_specs_1;
extern asn_TYPE_member_t asn_MBR_DeltaPosition_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _DeltaPosition_H_ */
#include "asn_internal.h"
