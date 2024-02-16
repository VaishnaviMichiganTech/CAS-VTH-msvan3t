/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_19321_IVI.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_DTM_H_
#define	_DTM_H_


#include "asn_application.h"

/* Including external dependencies */
#include "PMD.h"
#include "DayOfWeek.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"
#include "MonthDay.h"
#include "HoursMinutes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct HoursMinutes;

/* DTM */
typedef struct DTM {
	struct DTM__year {
		long	 syr;
		long	 eyr;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *year;
	struct DTM__month_day {
		MonthDay_t	 smd;
		MonthDay_t	 emd;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *month_day;
	PMD_t	*pmd	/* OPTIONAL */;
	struct DTM__hourMinutes {
		HoursMinutes_t	 shm;
		HoursMinutes_t	 ehm;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *hourMinutes;
	DayOfWeek_t	*dayOfWeek	/* OPTIONAL */;
	struct HoursMinutes	*period	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DTM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DTM;
extern asn_SEQUENCE_specifics_t asn_SPC_DTM_specs_1;
extern asn_TYPE_member_t asn_MBR_DTM_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "HoursMinutes.h"

#endif	/* _DTM_H_ */
#include "asn_internal.h"
