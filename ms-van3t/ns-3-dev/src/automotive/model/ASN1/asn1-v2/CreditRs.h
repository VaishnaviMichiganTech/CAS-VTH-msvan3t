/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EfcDsrcApplication"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_14906_EfcDsrcApplication.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_CreditRs_H_
#define	_CreditRs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ResultFin.h"
#include "OCTET_STRING.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CreditRs */
typedef struct CreditRs {
	ResultFin_t	 creditResult;
	OCTET_STRING_t	 creditAuthenticator;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CreditRs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CreditRs;

#ifdef __cplusplus
}
#endif

#endif	/* _CreditRs_H_ */
#include "asn_internal.h"
