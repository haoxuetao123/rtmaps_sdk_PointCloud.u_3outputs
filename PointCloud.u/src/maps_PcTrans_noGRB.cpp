////////////////////////////////
// RTMaps SDK Component
////////////////////////////////

////////////////////////////////
// Purpose of this module :
////////////////////////////////

#include "maps_PcTrans_noRGB.h"	// Includes the header of this component
#include <stdio.h>
#include <ctime>
#include <iostream>

// Use the macros to declare the inputs
MAPS_BEGIN_INPUTS_DEFINITION(MAPSPc_Trans_noRGB)
    MAPS_INPUT("XYZ0",MAPS::FilterFloat64,MAPS::FifoReader)
MAPS_END_INPUTS_DEFINITION

// Use the macros to declare the outputs
MAPS_BEGIN_OUTPUTS_DEFINITION(MAPSPc_Trans_noRGB)
    MAPS_OUTPUT("XYZ",MAPS::Float64,NULL,NULL,0)
MAPS_END_OUTPUTS_DEFINITION

// Use the macros to declare the properties
MAPS_BEGIN_PROPERTIES_DEFINITION(MAPSPc_Trans_noRGB)
    MAPS_PROPERTY("matrix0","1.0 0.0 0.0 0.0\n0.0 1.0 0.0 0.0\n0.0 0.0 1.0 0.0\n0.0 0.0 0.0 1.0",false,true)
MAPS_END_PROPERTIES_DEFINITION

// Use the macros to declare the actions
MAPS_BEGIN_ACTIONS_DEFINITION(MAPSPc_Trans_noRGB)
    //MAPS_ACTION("aName",MAPSPc_Trans_noRGB::ActionName)
MAPS_END_ACTIONS_DEFINITION

// Use the macros to declare this component (Pc_Trans_noRGB) behaviour
MAPS_COMPONENT_DEFINITION(MAPSPc_Trans_noRGB,"Pc_Trans_noRGB","1.0",128,
			  MAPS::Threaded,MAPS::Threaded,
			  -1, // Nb of inputs. Leave -1 to use the number of declared input definitions
			  -1, // Nb of outputs. Leave -1 to use the number of declared output definitions
			  -1, // Nb of properties. Leave -1 to use the number of declared property definitions
			  -1) // Nb of actions. Leave -1 to use the number of declared action definitions

// 4x4 matrix parser
//return 0 when no errors
int get_Matrix(MAPSMatrix2<double> &mx, const char *str) {
  double d[16];
  int res = sscanf(str, "%lf %lf %lf %lf\n%lf %lf %lf %lf\n%lf %lf %lf %lf\n%lf %lf %lf %lf", 
     &d[0], &d[1], &d[2], &d[3], &d[4], &d[5], &d[6], &d[7], 
     &d[8], &d[9], &d[10], &d[11], &d[12], &d[13], &d[14], &d[15] );
  if (res == 16) {
    mx = MAPSMatrix2<double>(4,4);
    mx = d;  //fill into matrix
    return 0;
  } else
    return -1;
}

//Initialization: Birth() will be called once at diagram execution startup.			  
void MAPSPc_Trans_noRGB::Birth()
{
  m_inputs[0] = &Input(0);


  if (0 != get_Matrix(matrix0, GetStringProperty("matrix0")))
    ReportError("Failed to parse matrix0. ");
  //if (0 != getMatrix(matrix1, GetStringProperty("matrix1")))
    //ReportError("Failed to parse matrix1. ");

#if 1
  MAPSStreamedString sx;
  sx << "matrix0: \n" << matrix0 << MAPSSManip::endl;
     //<< "matrix1: \n" << matrix1;
  ReportInfo(sx);
#endif

  m_firstTime = true;
}


int apply_Matrix(MAPSIOElt *ioEltIn, MAPSIOElt *ioEltOut, int shift, MAPSMatrix2<double> &matrix) {
  int vectorsize = ioEltIn->VectorSize(); 
  float a00 = matrix(0,0), a01 = matrix(0,1),a02 = matrix(0,2),
        a10 = matrix(1,0), a11 = matrix(1,1),a12 = matrix(1,2),
        a20 = matrix(2,0), a21 = matrix(2,1),a22 = matrix(2,2),
        a03 = matrix(0,3), a13 = matrix(1,3),a23 = matrix(2,3);

  double *pd = (double*)ioEltIn->Data();
  double *out = (double*)ioEltOut->Data();

  //#pragma omp parallel for num_threads(10)
  for (int i = vectorsize-1; i >= 0; i-=3) {
    //std::cout << "index i: " << i << std::endl;
    double x = *pd++;
    double y = *pd++;
    double z = *pd++;

    //pt = matrix * pt;
    *out++ = a00 *x + a01 *y + a02 *z + a03;
    *out++ = a10 *x + a11 *y + a12 *z + a13;
    *out++ = a20 *x + a21 *y + a22 *z + a23;
  }

  return 0;
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
//**************************************************************************/
//	In case of no blocking function inside the Core, your component will consume 100% of a CPU.
//  Remember that the StartReading function used with an input declared as a SamplingReader is not blocking.
//	In case of two or more blocking functions inside the Core, this is likely to induce synchronization issues and data loss. (Ex: don't call two successive StartReading on FifoReader inputs.)
/***************************************************************************/
void MAPSPc_Trans_noRGB::Core() 
{
  MAPSTimestamp ts0;

  int inputThatAnswered;
  MAPSIOElt *IOElt = StartReading(1, m_inputs, &inputThatAnswered);
  if (IOElt == NULL){
    //std::cout << "read no data" << std::endl;
    return;
  }
  else{
    m_lastIOElt[inputThatAnswered] = IOElt;
    //std::cout << "read data finished" << std::endl;
  }

  if (m_firstTime) {
    m_firstTime = false;
    Output(0).AllocOutputBuffer(m_lastIOElt[0]->BufferSize());
  }
  
  MAPSIOElt *ioEltOut = StartWriting(Output(0));
  if (ioEltOut == NULL)
    return;
	
  apply_Matrix(m_lastIOElt[0], ioEltOut, 0, matrix0);

  int vectorsize0 = m_lastIOElt[0]->VectorSize();
  ioEltOut->VectorSize() = vectorsize0;
  ts0 = m_lastIOElt[0]->Timestamp();
  ioEltOut->Timestamp() = ts0;
  StopWriting(ioEltOut);
  m_lastIOElt[0] = NULL;

}

//De-initialization: Death() will be called once at diagram execution shutdown.
void MAPSPc_Trans_noRGB::Death()
{
    // Reports this information to the RTMaps console. You can remove this line if you know when Death() is called in the component lifecycle.
    ReportInfo("Passing through Death() method");
}
