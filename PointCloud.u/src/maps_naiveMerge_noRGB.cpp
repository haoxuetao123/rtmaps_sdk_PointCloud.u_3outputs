////////////////////////////////
// RTMaps SDK Component
////////////////////////////////

////////////////////////////////
// Purpose of this module :
////////////////////////////////

#include "maps_naiveMerge_noRGB.h"	// Includes the header of this component
#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
// Use the macros to declare the inputs
MAPS_BEGIN_INPUTS_DEFINITION(MAPSnaiveMerge_noRGB)
    MAPS_INPUT("XYZ0",MAPS::FilterFloat64,MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

// Use the macros to declare the outputs
MAPS_BEGIN_OUTPUTS_DEFINITION(MAPSnaiveMerge_noRGB)
    MAPS_OUTPUT("xyz",MAPS::Float64,NULL,NULL,0)
    MAPS_OUTPUT("xyz_0",MAPS::Float64,NULL,NULL,0)
    MAPS_OUTPUT("xyz_1",MAPS::Float64,NULL,NULL,0)
    MAPS_OUTPUT("xyz_2",MAPS::Float64,NULL,NULL,0)
MAPS_END_OUTPUTS_DEFINITION


// Use the macros to declare the properties
MAPS_BEGIN_PROPERTIES_DEFINITION(MAPSnaiveMerge_noRGB)
    MAPS_PROPERTY("maxSyncTolerance", 50000, false, true)
    MAPS_PROPERTY("manualSync", true, false, false)
    MAPS_PROPERTY("nofinput", 1, true, false)
MAPS_END_PROPERTIES_DEFINITION

// Use the macros to declare the actions
MAPS_BEGIN_ACTIONS_DEFINITION(MAPSnaiveMerge_noRGB)
    //MAPS_ACTION("aName",MAPSnaiveMerge_noRGB::ActionName)
MAPS_END_ACTIONS_DEFINITION

// Use the macros to declare this component (naiveMerge_noRGB) behaviour
MAPS_COMPONENT_DEFINITION(MAPSnaiveMerge_noRGB,"naiveMerge_noRGB","1.0",128,
			  MAPS::Threaded,MAPS::Threaded,
			  0, // Nb of inputs. Leave -1 to use the number of declared input definitions
			  -1, // Nb of outputs. Leave -1 to use the number of declared output definitions
			  -1, // Nb of properties. Leave -1 to use the number of declared property definitions
			  -1) // Nb of actions. Leave -1 to use the number of declared action definitions


void MAPSnaiveMerge_noRGB::Dynamic()
{ 
  n_input = (int)GetIntegerProperty("nofinput"); // input number
  m_lastIOElt = new MAPSIOElt*[n_input];
  m_inputs = new MAPSInput*[n_input];
  char name[256] = {0};
  for (int i = 0; i < n_input; i++){
    sprintf(name, "xyz%d", i);
    NewInput(0, name);
  }    
}
//Initialization: Birth() will be called once at diagram execution startup.			  
void MAPSnaiveMerge_noRGB::Birth()
{
  m_synch_tolerance = (int)GetIntegerProperty("maxSyncTolerance");  //500ms
  m_bManualSync = GetBoolProperty("manualSync");
  m_firstTime = true;

  for (int j = 0; j < n_input; j++){
    m_inputs[j] = &Input(j);
    m_lastIOElt[j] = NULL;
  }
}


//ATTENTION: 
//	Make sure there is ONE and ONLY ONE blocking function inside this Core method.
//	Consider that Core() will be called inside an infinite loop while the diagram is executing.
//	Something similar to: 
//		while (componentIsRunning) {Core();}
//
//	Usually, the one and only blocking function is one of the following:
//		* StartReading(MAPSInput& input); //Data request on a single BLOCKING input. A "blocking input" is an input declared as FifoReader, LastOrNextReader, Wait4NextReader or NeverskippingReader (declaration happens in MAPS_INPUT: see the beginning of this file). A SamplingReader input is non-blocking: StartReading will not block with a SamplingReader input.
//		* StartReading(int nCount, MAPSInput* inputs[], int* inputThatAnswered, int nCountEvents = 0, MAPSEvent* events[] = NULL); //Data request on several BLOCKING inputs.
//		* SynchroStartReading(int nb, MAPSInput** inputs, MAPSIOElt** IOElts, MAPSInt64 synchroTolerance = 0, MAPSEvent* abortEvent = NULL); // Synchronized reading - waiting for samples with same or nearly same timestamps on several BLOCKING inputs.
//		* Wait(MAPSTimestamp t); or Rest(MAPSDelay d); or MAPS::Sleep(MAPSDelay d); //Pauses the current thread for some time. Can be used for instance in conjunction with StartReading on a SamplingReader input (in which case StartReading is not blocking).
//		* Any blocking grabbing function or other data reception function from another API (device driver,etc.). In such case, make sure this function cannot block forever otherwise it could freeze RTMaps when shutting down diagram.
//**************************************************************************/input
//	In case of no blocking function inside the Core, your component will consume 100% of a CPU.
//  Remember that the StartReading function used with an input declared as a SamplingReader is not blocking.
//	In case of two or more blocking functions inside the Core, this is likely to induce synchronization issues and data loss. (Ex: don't call two successive StartReading on FifoReader inputs.)
/***************************************************************************/
void MAPSnaiveMerge_noRGB::Core() 
{
  MAPSTimestamp ts = INT64_MAX;

  char buf[256];
  if (m_bManualSync) {
    int inputThatAnswered;
    MAPSIOElt *IOElt = StartReading(n_input, m_inputs, &inputThatAnsweredoriginal);
    if (IOElt == NULL) {
      return;
    } else
      m_lastIOElt[inputThatAnswered] = IOElt;
  } else {
    ts = SynchroStartReading(n_input, m_inputs, m_lastIOElt, m_synch_tolerance);
  }

  for (int j = 0; j < n_input; j++){
    if (m_lastIOElt[j] == NULL){
      return;
    }
  }

  if (m_bManualSync) {
    MAPSTimestamp n_ts[n_input];
    for (int j = 0; j < n_input; j++){
      n_ts[j] = m_lastIOElt[j]->Timestamp();
    }

    for (int i = 0; i < n_input; i++){
      for (int j = 0; j < n_input; j++){
        if(i==j) continue;
        if (n_ts[i] - n_ts[j] > m_synch_tolerance){
          m_lastIOElt[j] = NULL;
          sprintf(buf, "%ld too old compared with %ld %ld", n_ts[j],n_ts[i], n_ts[i] - n_ts[j]); ReportInfo(buf);
          return;
        } else if (n_ts[j] - n_ts[i] > m_synch_tolerance){
          m_lastIOElt[i] = NULL;
          sprintf(buf, "%ld too old compared with %ld %ld", n_ts[i],n_ts[j], n_ts[j] - n_ts[i]); ReportInfo(buf);
          return;
        }
        ts = (ts > n_ts[i] ? n_ts[i] : ts);//min()
        ts = (ts > n_ts[j] ? n_ts[j] : ts);//min()
      }
    }
  }


  if (m_firstTime) {
    m_firstTime = false;
    long long int out_size = 0;
    for (int i = 0; i < n_input; i++){
      out_size = out_size + m_lastIOElt[i]->BufferSize();
    }
    Output(0).AllocOutputBuffer(out_size);
    Output(1).AllocOutputBuffer(m_lastIOElt[0]->BufferSize());
    Output(2).AllocOutputBuffer(m_lastIOElt[1]->BufferSize());
    Output(3).AllocOutputBuffer(m_lastIOElt[2]->BufferSize());
  }

  MAPSIOElt *ioEltOut = StartWriting(Output(0));
  MAPSIOElt *ioEltOut_0 = StartWriting(Output(1));
  MAPSIOElt *ioEltOut_1 = StartWriting(Output(2));
  MAPSIOElt *ioEltOut_2 = StartWriting(Output(3));


  if (ioEltOut == NULL || ioEltOut_0 == NULL || ioEltOut_1 == NULL || ioEltOut_2 == NULL)
    return;
  
  // copy data
  std::memcpy(ioEltOut_0->Data(), m_lastIOElt[0]->Data(),m_lastIOElt[0]->VectorSize() * sizeof(MAPSFloat64));
  std::memcpy(ioEltOut_1->Data(), m_lastIOElt[1]->Data(),m_lastIOElt[1]->VectorSize() * sizeof(MAPSFloat64));
  std::memcpy(ioEltOut_2->Data(), m_lastIOElt[2]->Data(),m_lastIOElt[2]->VectorSize() * sizeof(MAPSFloat64));

  long long int out_index = 0;
  for (int i = 0; i < n_input; i++){
    std::memcpy(ioEltOut->Data() + out_index,m_lastIOElt[i]->Data(),m_lastIOElt[i]->VectorSize() * sizeof(MAPSFloat64));
    out_index = out_index + m_lastIOElt[i]->VectorSize() * sizeof(MAPSFloat64);
  }

  ioEltOut->VectorSize() = 0;
  ioEltOut_0->VectorSize() = m_lastIOElt[0]->VectorSize();
  ioEltOut_1->VectorSize() = m_lastIOElt[1]->VectorSize();
  ioEltOut_2->VectorSize() = m_lastIOElt[2]->VectorSize();

  for (int i = 0; i < n_input; i++){
    ioEltOut->VectorSize() = ioEltOut->VectorSize() + m_lastIOElt[i]->VectorSize();
  }


  ioEltOut_0->Timestamp() = m_lastIOElt[0]->Timestamp();
  ioEltOut_1->Timestamp() = m_lastIOElt[1]->Timestamp();
  ioEltOut_2->Timestamp() = m_lastIOElt[2]->Timestamp();

  ioEltOut->Timestamp() = ts;
  StopWriting(ioEltOut);
  StopWriting(ioEltOut_0);
  StopWriting(ioEltOut_1);
  StopWriting(ioEltOut_2);


  for (int i = 0; i < n_input; i++){
    m_lastIOElt[i] = NULL;
  }

}

//De-initialization: Death() will be called once at diagram execution shutdown.
void MAPSnaiveMerge_noRGB::Death()
{
    // Reports this information to the RTMaps console. You can remove this line if you know when Death() is called in the component lifecycle.
    ReportInfo("Passing through Death() method");
}
