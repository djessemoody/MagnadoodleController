/*
 * project6_model_capi.c
 *
 * Code generation for model "project6_model".
 *
 * Model version              : 1.349
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Thu Dec 05 17:01:07 2013
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "project6_model.h"
#include "rtw_capi.h"
#include "project6_model_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Derivative1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Gain",
    "", 0, 0, 1, 0, 1 },

  { 2, 0, "Kd",
    "", 0, 0, 0, 0, 0 },

  { 3, 0, "Ki",
    "", 0, 0, 0, 0, 0 },

  { 4, 0, "Kp",
    "", 0, 0, 0, 0, 1 },

  { 5, 0, "angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "Motor Position", 0, 0, 0, 0, 1 },

  { 6, 0, "gain",
    "Setpoint", 0, 0, 0, 0, 1 },

  { 7, 0, "Integrator1",
    "", 0, 0, 0, 0, 0 },

  { 8, 0, "Saturation",
    "", 0, 0, 0, 0, 0 },

  { 9, 0, "Channel 0 of  Encoder Inputs ",
    "", 0, 0, 0, 0, 1 },

  { 10, 0, "Sum1",
    "Error Signal", 0, 0, 0, 0, 1 },

  { 11, 0, "Sum4",
    "", 0, 0, 0, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 12, "Angle setpoint",
    "Value", 0, 0, 0 },

  { 13, "Darkness setpoint",
    "Value", 0, 0, 0 },

  { 14, "Gain",
    "Gain", 0, 0, 0 },

  { 15, "Kd",
    "Gain", 0, 0, 0 },

  { 16, "Ki",
    "Gain", 0, 0, 0 },

  { 17, "Kp",
    "Gain", 0, 0, 0 },

  { 18, "angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees",
    "Gain", 0, 0, 0 },

  { 19, "gain",
    "Gain", 0, 0, 0 },

  { 20, "Integrator1",
    "InitialCondition", 0, 0, 0 },

  { 21, "Saturation",
    "UpperLimit", 0, 0, 0 },

  { 22, "Saturation",
    "LowerLimit", 0, 0, 0 },

  { 23, "Channel 0 -Control signal to  motor through amplifier ",
    "P1", 0, 0, 0 },

  { 24, "Channel 0 -Control signal to  motor through amplifier ",
    "P2", 0, 2, 0 },

  { 25, "Channel 0 -Control signal to  motor through amplifier ",
    "P3", 0, 2, 0 },

  { 26, "Channel 0 -Control signal to  motor through amplifier ",
    "P4", 0, 0, 0 },

  { 27, "Channel 0 -Control signal to  motor through amplifier ",
    "P5", 0, 2, 0 },

  { 28, "Channel 0 -Control signal to  motor through amplifier ",
    "P6", 0, 2, 0 },

  { 29, "Channel 0 -Control signal to  motor through amplifier ",
    "P7", 0, 0, 0 },

  { 30, "Channel 0 -Control signal to  motor through amplifier ",
    "P8", 0, 0, 0 },

  { 31, "Channel 0 -Control signal to  motor through amplifier ",
    "P9", 0, 0, 0 },

  { 32, "Channel 0 of  Encoder Inputs ",
    "P1", 0, 0, 0 },

  { 33, "Channel 0 of  Encoder Inputs ",
    "P2", 0, 0, 0 },

  { 34, "Channel 0 of  Encoder Inputs ",
    "P3", 0, 0, 0 },

  { 35, "Channel 0 of  Encoder Inputs ",
    "P4", 0, 0, 0 },

  { 36, "Channel 0 of  Encoder Inputs ",
    "P5", 0, 0, 0 },

  { 37, "Channel 0 of  Encoder Inputs ",
    "P6", 0, 0, 0 },

  { 38, "Channel 0 of  Encoder Inputs ",
    "P7", 0, 0, 0 },

  { 39, "Channel 0 of  Encoder Inputs ",
    "P8", 0, 0, 0 },

  { 40, "Channel 0 of  Encoder Inputs ",
    "P9", 0, 0, 0 },

  { 41, "Channel 0 of  Encoder Inputs ",
    "P10", 0, 0, 0 },

  { 42, "Channel 0 of  Encoder Inputs ",
    "P11", 0, 0, 0 },

  { 43, "Channel 0 of  Encoder Inputs ",
    "P12", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &project6_model_B.Derivative1,       /* 0: Signal */
  &project6_model_B.Gain[0],           /* 1: Signal */
  &project6_model_B.Kd,                /* 2: Signal */
  &project6_model_B.Ki,                /* 3: Signal */
  &project6_model_B.Kp,                /* 4: Signal */
  &project6_model_B.MotorPosition,     /* 5: Signal */
  &project6_model_B.Setpoint,          /* 6: Signal */
  &project6_model_B.Integrator1,       /* 7: Signal */
  &project6_model_B.Saturation,        /* 8: Signal */
  &project6_model_B.Channel0ofEncoderInputs,/* 9: Signal */
  &project6_model_B.ErrorSignal,       /* 10: Signal */
  &project6_model_B.Sum4,              /* 11: Signal */
  &project6_model_P.Anglesetpoint_Value,/* 12: Block Parameter */
  &project6_model_P.Darknesssetpoint_Value,/* 13: Block Parameter */
  &project6_model_P.Gain_Gain,         /* 14: Block Parameter */
  &project6_model_P.Kd_Gain,           /* 15: Block Parameter */
  &project6_model_P.Ki_Gain,           /* 16: Block Parameter */
  &project6_model_P.Kp_Gain,           /* 17: Block Parameter */
  &project6_model_P.angular_positionrelative_countC,/* 18: Block Parameter */
  &project6_model_P.gain_Gain,         /* 19: Block Parameter */
  &project6_model_P.Integrator1_IC,    /* 20: Block Parameter */
  &project6_model_P.Saturation_UpperSat,/* 21: Block Parameter */
  &project6_model_P.Saturation_LowerSat,/* 22: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_p,/* 23: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_n[0],/* 24: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_c[0],/* 25: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_i,/* 26: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_m[0],/* 27: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_j[0],/* 28: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotor_l1,/* 29: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotor_co,/* 30: Block Parameter */
  &project6_model_P.Channel0Controlsignaltomotort_e,/* 31: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P1,/* 32: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P2,/* 33: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P3,/* 34: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P4,/* 35: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P5,/* 36: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P6,/* 37: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P7,/* 38: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P8,/* 39: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P9,/* 40: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P10,/* 41: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P11,/* 42: Block Parameter */
  &project6_model_P.Channel0ofEncoderInputs_P12/* 43: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  2                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.0001
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 12 },

  { rtBlockParameters, 32,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void project6_model_InitializeDataMapInfo(rtModel_project6_model
  *project6_model_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(project6_model_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(project6_model_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(project6_model_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(project6_model_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(project6_model_rtM->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(project6_model_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(project6_model_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(project6_model_rtM->DataMapInfo.mmi, 0);
}

/* EOF: project6_model_capi.c */
