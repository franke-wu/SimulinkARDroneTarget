/*
 *   dev_video2_sfcn.c Simple C-MEX S-function for function call.
 *
 *   ABSTRACT:
 *     The purpose of this sfunction is to call a simple legacy
 *     function during simulation:
 *
 *        videorabImage2(uint8 y1[153600])
 *
 *   Simulink version           : 8.7 (R2016a) 10-Feb-2016
 *   C source code generated on : 21-Apr-2016 15:52:41

 * THIS S-FUNCTION IS GENERATED BY THE LEGACY CODE TOOL AND MAY NOT WORK IF MODIFIED

 */

/*
   %%%-MATLAB_Construction_Commands_Start
   def = legacy_code('initialize');
   def.SFunctionName = 'dev_video2_sfcn';
   def.OutputFcnSpec = 'videorabImage2(uint8 y1[153600])';
   def.StartFcnSpec = 'void videoInit2(void)';
   def.TerminateFcnSpec = 'void videoClose2(void)';
   def.HeaderFiles = {'video.h'};
   def.SourceFiles = {'video.c'};
   def.SampleTime = 'parameterized';
   legacy_code('sfcn_cmex_generate', def);
   legacy_code('compile', def);
   %%%-MATLAB_Construction_Commands_End
 */

/*
 * Must specify the S_FUNCTION_NAME as the name of the S-function.
 */
#define S_FUNCTION_NAME                dev_video2_sfcn
#define S_FUNCTION_LEVEL               2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/*
 * Specific header file(s) required by the legacy code function.
 */
#include "video.h"
#define EDIT_OK(S, P_IDX) \
 (!((ssGetSimMode(S)==SS_SIMMODE_SIZES_CALL_ONLY) && mxIsEmpty(ssGetSFcnParam(S, P_IDX))))
#define SAMPLE_TIME                    (ssGetSFcnParam(S, 0))
#define isDWorkNeeded(S)               ((!((ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) && isSimulationTarget==0)) || ssIsRapidAcceleratorActive(S))

/*
 * Utility function prototypes.
 */
static bool IsRealMatrix(const mxArray *m);

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

/* Function: mdlCheckParameters ===========================================
 * Abstract:
 *    mdlCheckParameters verifies new parameter settings whenever parameter
 *    change or are re-evaluated during a simulation. When a simulation is
 *    running, changes to S-function parameters can occur at any time during
 *    the simulation loop.
 */
static void mdlCheckParameters(SimStruct *S)
{
  /*
   * Check the parameter 1 (sample time)
   */
  if EDIT_OK(S, 0) {
    real_T *sampleTime = NULL;
    mwSize stArraySize = mxGetM(SAMPLE_TIME) * mxGetN(SAMPLE_TIME);

    /* Sample time must be a real scalar value or 2 element array. */
    if (IsRealMatrix(SAMPLE_TIME) &&
        (stArraySize == 1 || stArraySize == 2) ) {
      sampleTime = (real_T *) mxGetPr(SAMPLE_TIME);
    } else {
      ssSetErrorStatus(S,
                       "Invalid sample time. Sample time must be a real scalar value or an array of two real values.");
      return;
    }

    if (sampleTime[0] < 0.0 && sampleTime[0] != -1.0) {
      ssSetErrorStatus(S,
                       "Invalid sample time. Period must be non-negative or -1 (for inherited).");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] > 0.0 &&
        sampleTime[1] >= sampleTime[0]) {
      ssSetErrorStatus(S,
                       "Invalid sample time. Offset must be smaller than period.");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] == -1.0 && sampleTime[1] != 0.0) {
      ssSetErrorStatus(S,
                       "Invalid sample time. When period is -1, offset must be 0.");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] == 0.0 &&
        !(sampleTime[1] == 1.0)) {
      ssSetErrorStatus(S,
                       "Invalid sample time. When period is 0, offset must be 1.");
      return;
    }
  }
}

#endif

#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS) && defined(MATLAB_MEX_FILE)

/* Function: mdlProcessParameters =========================================
 * Abstract:
 *    Update run-time parameters.
 */
static void mdlProcessParameters(SimStruct *S)
{
  /* Update Run-Time parameters */
  ssUpdateAllTunableParamsAsRunTimeParams(S);
}

#endif

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
  /* Number of expected parameters */
  ssSetNumSFcnParams(S, 1);

#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
    /*
     * If the number of expected input parameters is not equal
     * to the number of parameters entered in the dialog box return.
     * Simulink will generate an error indicating that there is a
     * parameter mismatch.
     */
    mdlCheckParameters(S);
    if (ssGetErrorStatus(S) != NULL) {
      return;
    }
  } else {
    /* Return if number of expected != number of actual parameters */
    return;
  }

#endif

  /* Set the parameter's tunability */
  ssSetSFcnParamTunable(S, 0, 0);

  /*
   * Set the number of work vectors.
   */
  if (!ssSetNumDWork(S, 0))
    return;
  ssSetNumPWork(S, 0);

  /*
   * Set the number of input ports.
   */
  if (!ssSetNumInputPorts(S, 0))
    return;

  /*
   * Set the number of output ports.
   */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /*
   * Configure the output port 1
   */
  ssSetOutputPortDataType(S, 0, SS_UINT8);
  ssSetOutputPortWidth(S, 0, 153600);
  ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
  ssSetOutputPortOutputExprInRTW(S, 0, 0);

  /*
   * Register reserved identifiers to avoid name conflict
   */
  if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {
    /*
     * Register reserved identifier for StartFcnSpec
     */
    ssRegMdlInfo(S, "videoInit2", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

    /*
     * Register reserved identifier for OutputFcnSpec
     */
    ssRegMdlInfo(S, "videorabImage2", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));

    /*
     * Register reserved identifier for TerminateFcnSpec
     */
    ssRegMdlInfo(S, "videoClose2", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
  }

  /*
   * This S-function can be used in referenced model simulating in normal mode.
   */
  ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

  /*
   * Set the number of sample time.
   */
  ssSetNumSampleTimes(S, 1);

  /*
   * Set the compliance with the SimState feature.
   */
  ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

  /*
   * All options have the form SS_OPTION_<name> and are documented in
   * matlabroot/simulink/include/simstruc.h. The options should be
   * bitwise or'd together as in
   *   ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
   */
  ssSetOptions(S,
               SS_OPTION_USE_TLC_WITH_ACCELERATOR |
               SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
               SS_OPTION_EXCEPTION_FREE_CODE |
               SS_OPTION_WORKS_WITH_CODE_REUSE |
               SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
               SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME);
  ssSetSimulinkVersionGeneratedIn(S, "8.7");
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  real_T * sampleTime = (real_T*) (mxGetPr(SAMPLE_TIME));
  mwSize stArraySize = mxGetM(SAMPLE_TIME) * mxGetN(SAMPLE_TIME);
  ssSetSampleTime(S, 0, sampleTime[0]);
  if (stArraySize == 1) {
    ssSetOffsetTime(S, 0, (sampleTime[0] == CONTINUOUS_SAMPLE_TIME?
      FIXED_IN_MINOR_STEP_OFFSET: 0.0));
  } else {
    ssSetOffsetTime(S, 0, sampleTime[1]);
  }

#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)

  ssSetModelReferenceSampleTimeDefaultInheritance(S);

#endif

}

#define MDL_START
#if defined(MDL_START)

/* Function: mdlStart =====================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
  /*
   * Call the legacy code function
   */
  videoInit2();
}

#endif

/* Function: mdlOutputs ===================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector(s),
 *    ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /*
   * Get access to Parameter/Input/Output/DWork/size information
   */
  uint8_T *y1 = (uint8_T *) ssGetOutputPortSignal(S, 0);

  /*
   * Call the legacy code function
   */
  videorabImage2( y1);
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
  /*
   * Call the legacy code function
   */
  videoClose2();
}

#define MDL_RTW
#if defined(MATLAB_MEX_FILE) && defined(MDL_RTW)

/* Function: mdlRTW =======================================================
 * Abstract:
 *    This function is called when Simulink Coder is generating
 *    the model.rtw file.
 */
static void mdlRTW(SimStruct *S)
{
}

#endif

/* Function: IsRealMatrix =================================================
 * Abstract:
 *      Verify that the mxArray is a real (double) finite matrix
 */
bool IsRealMatrix(const mxArray *m)
{
  if (mxIsNumeric(m) &&
      mxIsDouble(m) &&
      !mxIsLogical(m) &&
      !mxIsComplex(m) &&
      !mxIsSparse(m) &&
      !mxIsEmpty(m) &&
      mxGetNumberOfDimensions(m) == 2) {
    real_T *data = mxGetPr(m);
    mwSize numEl = mxGetNumberOfElements(m);
    mwSize i;
    for (i = 0; i < numEl; i++) {
      if (!mxIsFinite(data[i])) {
        return(false);
      }
    }

    return(true);
  } else {
    return(false);
  }
}

/*
 * Required S-function trailer
 */
#ifdef MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif
