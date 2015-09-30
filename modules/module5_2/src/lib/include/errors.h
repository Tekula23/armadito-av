/**
 * @file   errors.h
 *
 * This file define a set of custom errors code used by the module.
 */

#ifndef ERRORS_H
#define ERRORS_H

#include "windowsTypes.h"

typedef enum _ERROR_CODE{
	/* _ERROR_CODE initialization value */
	UH_NULL 						=  000,
	/* no error return value : 1xx */

	UH_SUCCESS 					=  100,
	UH_MALWARE 					=  101,
	UH_NOT_MALWARE 				=  102,
	UH_EAT_UNKNOWN 				=  103,
	UH_TFIDF_UNKNOWN 			=  104,
	UH_NOT_DECIDED 				=  105,
	/* global errors :         2xx */

	E_READING_ERROR 			=  201,
	E_TEST_ERROR 				=  202,
	E_DISTANCE_ERROR 			=  203,
	E_FAILURE 					=  204,
	E_CALLOC_ERROR 				=  205,
	E_FILE_NOT_FOUND 			=  206,
	E_FILE_EMPTY 				=  207,
	/* pe errors :             3xx */

	E_NOT_MZ 					=  300,
	E_NOT_PE 					=  301,
	E_BAD_ARCHITECTURE 			=  302,
	UH_NO_SECTIONS				=  303,
	E_NO_ENTRY_POINT 			=  305,
	E_EAT_EMPTY 				=  306,
	E_IAT_EMPTY 				=  307,
	E_SECTION_ERROR 			=  308,
	E_DLL_NAME_ERROR 			=  309,
	E_FUNCTION_NAME_ERROR		=  314,
	E_NAME_ERROR 				=  310,
	E_CHECKSUM_ERROR 			=  311,
	E_IAT_NOT_GOOD 				=  312,
	E_EAT_NOT_GOOD 				=  313,
	UH_INVALID_SECTION_NAME		=  316,
	E_NO_ENTRY 					=  315,
	E_INVALID_ENTRY_POINT 		=  320,
	E_INVALID_STUB		 		=  321,
	E_INVALID_TIMESTAMP 		=  322,
	E_FIELDS_WITH_INVALID_VALUE =  323,
	E_INVALID_SIZE_OPT_HEADER 	=  324,
	E_EAT_INVALID_TIMESTAMP		=  325,
	E_IAT_INVALID_TIMESTAMP		=  326,
	E_EMPTY_VECTOR				=  327,
	E_INVALID_STRUCTURE			=  328,
	E_INVALID_NUMBER_RVA_SIZES  =  329,
	E_INVALID_FILE_SIZE			=  330,
	E_HEADER_NOT_GOOD			=  331,
	E_INVALID_S_F_ALIGNMENT		=  332,
	UH_INVALID_SECTION			=  333
} ERROR_CODE, *PERROR_CODE;

VOID SetCurrentError(ERROR_CODE error);
ERROR_CODE GetCurrentError();
CHAR* GetErrorCodeMsg(ERROR_CODE error);

#endif /* ERRORS_H */
