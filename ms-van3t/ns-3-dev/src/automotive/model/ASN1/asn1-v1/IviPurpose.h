/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IVI"
 * 	found in "ASN1Files/ISO_TS_19321.asn"
 * 	`asn1c -fincludes-quoted`
 */

#ifndef	_IviPurpose_H_
#define	_IviPurpose_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IviPurpose {
	IviPurpose_safety	= 0,
	IviPurpose_environmental	= 1,
	IviPurpose_trafficOptimisation	= 2
} e_IviPurpose;

/* IviPurpose */
typedef long	 IviPurpose_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IviPurpose_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IviPurpose;
asn_struct_free_f IviPurpose_free;
asn_struct_print_f IviPurpose_print;
asn_constr_check_f IviPurpose_constraint;
ber_type_decoder_f IviPurpose_decode_ber;
der_type_encoder_f IviPurpose_encode_der;
xer_type_decoder_f IviPurpose_decode_xer;
xer_type_encoder_f IviPurpose_encode_xer;
oer_type_decoder_f IviPurpose_decode_oer;
oer_type_encoder_f IviPurpose_encode_oer;
per_type_decoder_f IviPurpose_decode_uper;
per_type_encoder_f IviPurpose_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _IviPurpose_H_ */
#include "asn_internal.h"
