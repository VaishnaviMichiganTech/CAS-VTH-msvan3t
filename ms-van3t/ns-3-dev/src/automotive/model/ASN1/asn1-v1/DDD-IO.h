/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "ASN1Files/ISO_TS_19321.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_DDD_IO_H_
#define	_DDD_IO_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "UTF8String.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DistanceOrDuration;
struct DestinationPlace;
struct DestinationRoad;

/* DDD-IO */
typedef struct DDD_IO {
	long	 drn;
	struct DDD_IO__dp {
		A_SEQUENCE_OF(struct DestinationPlace) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *dp;
	struct DDD_IO__dr {
		A_SEQUENCE_OF(struct DestinationRoad) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *dr;
	long	*rne	/* OPTIONAL */;
	long	*stnId	/* OPTIONAL */;
	UTF8String_t	*stnText	/* OPTIONAL */;
	struct DistanceOrDuration	*dcp	/* OPTIONAL */;
	struct DistanceOrDuration	*ddp	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DDD_IO_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DDD_IO;
extern asn_SEQUENCE_specifics_t asn_SPC_DDD_IO_specs_1;
extern asn_TYPE_member_t asn_MBR_DDD_IO_1[8];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DistanceOrDuration.h"
#include "DestinationPlace.h"
#include "DestinationRoad.h"

#endif	/* _DDD_IO_H_ */
#include "asn_internal.h"
