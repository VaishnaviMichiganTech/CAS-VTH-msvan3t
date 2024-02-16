/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "../IVIM-ASN1-files/asn1_IS_ISO_TS_19321_IVI.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef	_ISO14823Attribute_H_
#define	_ISO14823Attribute_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DTM.h"
#include "EDT.h"
#include "DFL.h"
#include "VED.h"
#include "SPE.h"
#include "ROI.h"
#include "DBV.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ISO14823Attribute_PR {
	ISO14823Attribute_PR_NOTHING,	/* No components present */
	ISO14823Attribute_PR_dtm,
	ISO14823Attribute_PR_edt,
	ISO14823Attribute_PR_dfl,
	ISO14823Attribute_PR_ved,
	ISO14823Attribute_PR_spe,
	ISO14823Attribute_PR_roi,
	ISO14823Attribute_PR_dbv,
	ISO14823Attribute_PR_ddd
} ISO14823Attribute_PR;

/* Forward declarations */
struct DDD;

/* ISO14823Attribute */
typedef struct ISO14823Attribute {
	ISO14823Attribute_PR present;
	union ISO14823Attribute_u {
		DTM_t	 dtm;
		EDT_t	 edt;
		DFL_t	 dfl;
		VED_t	 ved;
		SPE_t	 spe;
		ROI_t	 roi;
		DBV_t	 dbv;
		struct DDD	*ddd;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ISO14823Attribute_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ISO14823Attribute;
extern asn_CHOICE_specifics_t asn_SPC_ISO14823Attribute_specs_1;
extern asn_TYPE_member_t asn_MBR_ISO14823Attribute_1[8];
extern asn_per_constraints_t asn_PER_type_ISO14823Attribute_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DDD.h"

#endif	/* _ISO14823Attribute_H_ */
#include "asn_internal.h"