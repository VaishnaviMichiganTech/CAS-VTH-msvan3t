/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_19321_IVI.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_VehicleCharacteristicsFixValues_H_
#define	_VehicleCharacteristicsFixValues_H_


#include "asn_application.h"

/* Including external dependencies */
#include "StationType.h"
#include "EuVehicleCategoryCode.h"
#include "Iso3833VehicleType.h"
#include "EnvironmentalCharacteristics.h"
#include "EngineCharacteristics.h"
#include "LoadType.h"
#include "VehicleRole.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum VehicleCharacteristicsFixValues_PR {
	VehicleCharacteristicsFixValues_PR_NOTHING,	/* No components present */
	VehicleCharacteristicsFixValues_PR_simpleVehicleType,
	VehicleCharacteristicsFixValues_PR_euVehicleCategoryCode,
	VehicleCharacteristicsFixValues_PR_iso3833VehicleType,
	VehicleCharacteristicsFixValues_PR_euroAndCo2value,
	VehicleCharacteristicsFixValues_PR_engineCharacteristics,
	VehicleCharacteristicsFixValues_PR_loadType,
	VehicleCharacteristicsFixValues_PR_usage
	/* Extensions may appear below */
	
} VehicleCharacteristicsFixValues_PR;

/* VehicleCharacteristicsFixValues */
typedef struct VehicleCharacteristicsFixValues {
	VehicleCharacteristicsFixValues_PR present;
	union VehicleCharacteristicsFixValues_u {
		StationType_t	 simpleVehicleType;
		EuVehicleCategoryCode_t	 euVehicleCategoryCode;
		Iso3833VehicleType_t	 iso3833VehicleType;
		EnvironmentalCharacteristics_t	 euroAndCo2value;
		EngineCharacteristics_t	 engineCharacteristics;
		LoadType_t	 loadType;
		VehicleRole_t	 usage;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} VehicleCharacteristicsFixValues_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_VehicleCharacteristicsFixValues;
extern asn_CHOICE_specifics_t asn_SPC_VehicleCharacteristicsFixValues_specs_1;
extern asn_TYPE_member_t asn_MBR_VehicleCharacteristicsFixValues_1[7];
extern asn_per_constraints_t asn_PER_type_VehicleCharacteristicsFixValues_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _VehicleCharacteristicsFixValues_H_ */
#include "asn_internal.h"
