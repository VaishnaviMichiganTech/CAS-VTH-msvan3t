/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "ASN1Files/ISO_TS_19321.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_TcPart_H_
#define	_TcPart_H_


#include "asn_application.h"

/* Including external dependencies */
#include "Direction.h"
#include "NativeInteger.h"
#include "OCTET_STRING.h"
#include "Zid.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"
#include "LanePosition.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Text;

/* TcPart */
typedef struct TcPart {
	struct TcPart__detectionZoneIds {
		A_SEQUENCE_OF(Zid_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *detectionZoneIds;
	struct TcPart__relevanceZoneIds {
		A_SEQUENCE_OF(Zid_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} relevanceZoneIds;
	Direction_t	*direction	/* OPTIONAL */;
	struct TcPart__driverAwarenessZoneIds {
		A_SEQUENCE_OF(Zid_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *driverAwarenessZoneIds;
	long	*minimumAwarenessTime	/* OPTIONAL */;
	struct TcPart__applicableLanes {
		A_SEQUENCE_OF(LanePosition_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *applicableLanes;
	long	*layoutId	/* OPTIONAL */;
	long	*preStoredlayoutId	/* OPTIONAL */;
	struct TcPart__text {
		A_SEQUENCE_OF(struct Text) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *text;
	OCTET_STRING_t	 data;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TcPart_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TcPart;
extern asn_SEQUENCE_specifics_t asn_SPC_TcPart_specs_1;
extern asn_TYPE_member_t asn_MBR_TcPart_1[10];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Text.h"

#endif	/* _TcPart_H_ */
#include "asn_internal.h"
