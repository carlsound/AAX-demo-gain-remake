/*================================================================================================*/

/**  
 *	\file   DemoGainRemake_Defs.h
 *
 *	\brief  Definitions shared by the DemoGain classes in one easy-to-maintain file.
 */ 
/*================================================================================================*/

#pragma once
#ifndef DEMOGAINREMAKE_DEFS_H
#define DEMOGAINREMAKE_DEFS_H

#include "/Users/johncarlson/Downloads/Avid/AAX_SDK_2p2p2/Interfaces/AAX.h"			// for AAX_CTypeID


// Type, product, and relation IDs
const AAX_CTypeID cDemoGain_ManufactureID =			'PRGM';
const AAX_CTypeID cDemoGain_ProductID =				'DGRM';
const AAX_CTypeID cDemoGain_PlugInID_Native =		'DGDR';
const AAX_CTypeID cDemoGain_PlugInID_AudioSuite =	'DGDA';
const AAX_CTypeID cDemoGain_PlugInID_TI =			'DGDT';

const AAX_CTypeID cDemoGain_MeterID [2] =			{'mtrI','mtrO'};

#define DemoGainRemake_GainID		"Gain"

#endif // DEMOGAIN_DEFS_H
