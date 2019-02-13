////////////////////////////////
// RTMaps SDK Component header
////////////////////////////////

#ifndef _Maps_naiveMerge_noRGB_H
#define _Maps_naiveMerge_noRGB_H

// Includes maps sdk library header
#include "maps.hpp"

// Declares a new MAPSComponent child class
class MAPSnaiveMerge_noRGB : public MAPSComponent 
{
	// Use standard header definition macro
	MAPS_COMPONENT_STANDARD_HEADER_CODE(MAPSnaiveMerge_noRGB)
private :
	// Place here your specific methods and attributes
	int n_input;
	void Dynamic();
	MAPSDelay m_synch_tolerance;
	bool m_bManualSync;
	bool m_firstTime;
	MAPSIOElt** m_lastIOElt;
  	MAPSInput** m_inputs;
};

#endif
