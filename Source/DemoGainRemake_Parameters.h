/*================================================================================================*/

/**  
 *	\file   DemoGain_Parameters.h
 *
 *	\brief  DemoGain_Parameters class declaration.
 */ 
/*================================================================================================*/ 

#pragma once
#ifndef DEMOGAINREMAKE_PARAMETERS_H
#define DEMOGAINREMAKE_PARAMETERS_H

#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_CEffectParameters.h"


class DemoGainRemake_Parameters : public AAX_CEffectParameters
{
public:
	DemoGainRemake_Parameters (void);
	virtual ~DemoGainRemake_Parameters (void) {}
	
	// Create callback
	static AAX_CEffectParameters *AAX_CALLBACK Create();

public:
	//Overrides from AAX_CEffectParameters
	virtual AAX_Result EffectInit();

private:
	AAX_Result UpdatePacket_Gain(AAX_CPacket& ioPacket);
};


#endif
