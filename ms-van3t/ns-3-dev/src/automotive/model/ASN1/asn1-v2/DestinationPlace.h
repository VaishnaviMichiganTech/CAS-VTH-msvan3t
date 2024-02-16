/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "/home/carlosrisma/IVIM ASN1 files/asn1_IS_ISO_TS_19321_IVI.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_DestinationPlace_H_
#define	_DestinationPlace_H_


#include "asn_application.h"

/* Including external dependencies */
#include "DDD-DEP.h"
#include "OCTET_STRING.h"
#include "NativeInteger.h"
#include "UTF8String.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ISO14823Code;

/* DestinationPlace */
typedef struct DestinationPlace {
	DDD_DEP_t	 depType;
	struct ISO14823Code	*depRSCode	/* OPTIONAL */;
	OCTET_STRING_t	*depBlob	/* OPTIONAL */;
	long	*plnId	/* OPTIONAL */;
	UTF8String_t	*plnText	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DestinationPlace_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DestinationPlace;
extern asn_SEQUENCE_specifics_t asn_SPC_DestinationPlace_specs_1;
extern asn_TYPE_member_t asn_MBR_DestinationPlace_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ISO14823Code.h"

#endif	/* _DestinationPlace_H_ */
#include "asn_internal.h"
