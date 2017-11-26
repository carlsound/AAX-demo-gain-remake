/*================================================================================================*/

/**  
 *	\file   DemoGain_Alg.h
 *
 *	\brief  Algorithm component definitions for DemoGain.
 *
 *  \author
 */ 
/*================================================================================================*/

#pragma once
#ifndef DEMOGAINREMAKE_ALG_H
#define DEMOGAINREMAKE_ALG_H



// AAX includes
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX.h"
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_Push8ByteStructAlignment.h"
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_PopStructAlignment.h"


//==============================================================================
// General definitions
//==============================================================================

// Meter layout
enum EDemoGainRemake_MeterTaps
{
	eMeterTap_PreGain = 0,
	eMeterTap_PostGain,

	eMeterTap_Count
};


//==============================================================================
// Memory block structure definitions
//==============================================================================

//#include AAX_ALIGN_FILE_ALG
	// Gain coefficient structure (extend this to add more coeffs)
	struct SDemoGainRemake_CoefsGain
	{
		float	mGain;
	};
//#include AAX_ALIGN_FILE_RESET

//==============================================================================
// Component context definitions
//==============================================================================

// Context structure
struct SDemoGainRemake_Alg_Context
{
	int32_t						* mCtrlBypassP;					// Control message destination

	SDemoGainRemake_CoefsGain			* mCoefsGainP;					// Inter-component message destination
	
	float*						* mInputPP;						// Audio signal destination
	float*						* mOutputPP;					// Audio signal source
	int32_t						* mBufferSize;					// Buffer size

	float*						* mMetersPP;					// Meter taps
};


// Physical addresses within the context
enum EDemoGainRemake_Alg_PortID
{
	 eAlgPortID_BypassIn					= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mCtrlBypassP)
	,eAlgPortID_CoefsGainIn					= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mCoefsGainP)
	
	,eAlgFieldID_AudioIn					= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mInputPP)
	,eAlgFieldID_AudioOut					= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mOutputPP)
	,eAlgFieldID_BufferSize					= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mBufferSize)

	,eAlgFieldID_Meters						= AAX_FIELD_INDEX (SDemoGainRemake_Alg_Context, mMetersPP)
};


//==============================================================================
// Callback declarations
//==============================================================================

void
AAX_CALLBACK
DemoGainRemake_AlgorithmProcessFunction (
    SDemoGainRemake_Alg_Context * const	inInstancesBegin [],
    const void *					inInstancesEnd);

#endif //DEMOGAINREMAKE_ALG_H
