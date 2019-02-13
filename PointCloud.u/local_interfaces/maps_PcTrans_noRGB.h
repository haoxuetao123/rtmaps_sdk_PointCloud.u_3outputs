////////////////////////////////
// RTMaps SDK Component header
////////////////////////////////

#ifndef _Maps_PcTrans_noRGB_H
#define _Maps_PcTrans_noRGB_H

// Includes maps sdk library header
#include "maps.hpp"

// Declares a new MAPSComponent child class
class MAPSPc_Trans_noRGB : public MAPSComponent 
{
	// Use standard header definition macro
	MAPS_COMPONENT_STANDARD_HEADER_CODE(MAPSPc_Trans_noRGB)
private :
	// Place here your specific methods and attributes
	MAPSMatrix2<double> matrix0;
	MAPSIOElt* m_lastIOElt[1];
	MAPSInput* m_inputs[1];
	bool m_bCopyRGBToOutput;
        bool m_firstTime;
};

#endif
