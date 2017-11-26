/*================================================================================================*/
/*
 *	Copyright 2009-2015 by Avid Technology, Inc.
 *	All rights reserved.
 *
 *	CONFIDENTIAL: This document contains confidential information.  Do not 
 *	read or examine this document unless you are an Avid Technology employee
 *	or have signed a non-disclosure agreement with Avid Technology which protects
 *	the	confidentiality of this document.  DO NOT DISCLOSE ANY INFORMATION 
 *	CONTAINED IN THIS DOCUMENT TO ANY THIRD-PARTY WITHOUT THE PRIOR WRITTEN	CONSENT 
 *	OF Avid Technology, INC.
 */
/*================================================================================================*/ 

#include "DemoGainRemake_Parameters.h"
#include "DemoGainRemake_Defs.h"
#include "DemoGainRemake_Alg.h"

#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_CBinaryTaperDelegate.h"
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_CBinaryDisplayDelegate.h"
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_CLinearTaperDelegate.h"
#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_CNumberDisplayDelegate.h"

#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX_Assert.h"



// *******************************************************************************
// ROUTINE:	Create
// *******************************************************************************
AAX_CEffectParameters *AAX_CALLBACK DemoGainRemake_Parameters::Create()
{
	return new DemoGainRemake_Parameters();
}

// *******************************************************************************
// METHOD:	DemoGain_Parameters
// *******************************************************************************
DemoGainRemake_Parameters::DemoGainRemake_Parameters () :
	AAX_CEffectParameters()
{
}

// *******************************************************************************
// METHOD:	EffectInit
// *******************************************************************************
AAX_Result DemoGainRemake_Parameters::EffectInit()
{	
	// bypass
	AAX_CString bypassID = cDefaultMasterBypassID;
	AAX_IParameter * masterBypass = new AAX_CParameter<bool>(
		bypassID.CString(), AAX_CString("Master Bypass"), false,
		AAX_CBinaryTaperDelegate<bool>(),
		AAX_CBinaryDisplayDelegate<bool>("bypass", "on"), true);
	masterBypass->SetNumberOfSteps( 2 );
	masterBypass->SetType( AAX_eParameterType_Discrete );
	mParameterManager.AddParameter(masterBypass);
	
	// gain
	AAX_CParameter<float>* gainParameter = new AAX_CParameter<float>(
		DemoGainRemake_GainID, AAX_CString("Gain"), 1.0f,
		AAX_CLinearTaperDelegate<float>(0.0f, 1.0f),
		AAX_CNumberDisplayDelegate<float>(), true);
	gainParameter->SetNumberOfSteps(55);
	mParameterManager.AddParameter(gainParameter);

	// register packets
	mPacketDispatcher.RegisterPacket(bypassID.CString(), eAlgPortID_BypassIn);
	mPacketDispatcher.RegisterPacket(DemoGainRemake_GainID, eAlgPortID_CoefsGainIn, this, &DemoGainRemake_Parameters::UpdatePacket_Gain);

	return AAX_SUCCESS;
}

// *******************************************************************************
// METHOD:	UpdatePacketGain
// *******************************************************************************
AAX_Result DemoGainRemake_Parameters::UpdatePacket_Gain( AAX_CPacket& ioPacket )
{
	AAX_IParameter*	 parameter = mParameterManager.GetParameterByID( DemoGainRemake_GainID );
	if (parameter)
	{
		float floatValue;
		if (parameter->GetValueAsFloat(&floatValue))
		{
			SDemoGainRemake_CoefsGain&  packet = *ioPacket.GetPtr<SDemoGainRemake_CoefsGain>();
			
			// Populate packet
			packet.mGain = floatValue;
		}
	}
	return AAX_SUCCESS;
}
