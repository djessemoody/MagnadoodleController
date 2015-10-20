/*
 * project6_model.c
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
#include "rt_logging_mmi.h"
#include "project6_model_capi.h"
#include "project6_model.h"
#include "project6_model_private.h"
#include "project6_model_dt.h"

/* Block signals (auto storage) */
BlockIO_project6_model project6_model_B;

/* Continuous states */
ContinuousStates_project6_model project6_model_X;

/* Block states (auto storage) */
D_Work_project6_model project6_model_DWork;

/* Real-time model */
rtModel_project6_model project6_model_rtM_;
rtModel_project6_model *const project6_model_rtM = &project6_model_rtM_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  project6_model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  project6_model_output();
  project6_model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  project6_model_output();
  project6_model_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void project6_model_output(void)
{
  real_T u;
  real_T u_0;
  real_T u_1;
  if (rtmIsMajorTimeStep(project6_model_rtM)) {
    /* set solver stop time */
    if (!(project6_model_rtM->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&project6_model_rtM->solverInfo,
                            ((project6_model_rtM->Timing.clockTickH0 + 1) *
        project6_model_rtM->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&project6_model_rtM->solverInfo,
                            ((project6_model_rtM->Timing.clockTick0 + 1) *
        project6_model_rtM->Timing.stepSize0 +
        project6_model_rtM->Timing.clockTickH0 *
        project6_model_rtM->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(project6_model_rtM)) {
    project6_model_rtM->Timing.t[0] = rtsiGetT(&project6_model_rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(project6_model_rtM)) {
    /* Gain: '<Root>/gain' incorporates:
     *  Constant: '<Root>/Angle setpoint'
     */
    project6_model_B.Setpoint = project6_model_P.gain_Gain *
      project6_model_P.Anglesetpoint_Value;

    /* Level2 S-Function Block: '<Root>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
    {
      SimStruct *rts = project6_model_rtM->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    project6_model_B.MotorPosition =
      project6_model_P.angular_positionrelative_countC *
      project6_model_B.Channel0ofEncoderInputs;

    /* Sum: '<Root>/Sum1' */
    project6_model_B.ErrorSignal = project6_model_B.Setpoint
      - project6_model_B.MotorPosition;

    /* Gain: '<Root>/Kp' */
    project6_model_B.Kp = project6_model_P.Kp_Gain *
      project6_model_B.ErrorSignal;
  }

  /* Integrator: '<Root>/Integrator1' */
  project6_model_B.Integrator1 = project6_model_X.Integrator1_CSTATE;

  /* Gain: '<Root>/Ki' */
  project6_model_B.Ki = project6_model_P.Ki_Gain * project6_model_B.Integrator1;

  /* Derivative: '<Root>/Derivative1' */
  {
    real_T t = project6_model_rtM->Timing.t[0];
    real_T timeStampA = project6_model_DWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = project6_model_DWork.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      project6_model_B.Derivative1 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      project6_model_B.Derivative1 = (project6_model_B.ErrorSignal - *lastU++) /
        deltaT;
    }
  }

  /* Gain: '<Root>/Kd' */
  project6_model_B.Kd = project6_model_P.Kd_Gain * project6_model_B.Derivative1;

  /* Sum: '<Root>/Sum4' */
  project6_model_B.Sum4 = (project6_model_B.Kp + project6_model_B.Ki) +
    project6_model_B.Kd;

  /* Saturate: '<Root>/Saturation' */
  u = project6_model_B.Sum4;
  u_0 = project6_model_P.Saturation_LowerSat;
  u_1 = project6_model_P.Saturation_UpperSat;
  if (u >= u_1) {
    project6_model_B.Saturation = u_1;
  } else if (u <= u_0) {
    project6_model_B.Saturation = u_0;
  } else {
    project6_model_B.Saturation = u;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(project6_model_rtM)) {
    /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
    {
      SimStruct *rts = project6_model_rtM->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S1>/S-Function */
    project6_model_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S2>/S-Function */
    project6_model_DWork.SFunction_IWORK_e.AcquireOK = 1;

    /* ok to acquire for <S3>/S-Function */
    project6_model_DWork.SFunction_IWORK_a.AcquireOK = 1;

    /* ok to acquire for <S4>/S-Function */
    project6_model_DWork.SFunction_IWORK_aj.AcquireOK = 1;

    /* Gain: '<Root>/Gain' */
    project6_model_B.Gain[0] = project6_model_P.Gain_Gain *
      project6_model_B.Setpoint;
    project6_model_B.Gain[1] = project6_model_P.Gain_Gain *
      project6_model_B.MotorPosition;
    project6_model_B.Gain[2] = project6_model_P.Gain_Gain *
      project6_model_B.ErrorSignal;
  }
}

/* Model update function */
void project6_model_update(void)
{
  /* Update for Derivative: '<Root>/Derivative1' */
  {
    real_T timeStampA = project6_model_DWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = project6_model_DWork.Derivative1_RWORK.TimeStampB;
    real_T* lastTime = &project6_model_DWork.Derivative1_RWORK.TimeStampA;
    real_T* lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &project6_model_DWork.Derivative1_RWORK.TimeStampB;
        lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &project6_model_DWork.Derivative1_RWORK.TimeStampB;
        lastU = &project6_model_DWork.Derivative1_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = project6_model_rtM->Timing.t[0];
    *lastU++ = project6_model_B.ErrorSignal;
  }

  if (rtmIsMajorTimeStep(project6_model_rtM)) {
    rt_ertODEUpdateContinuousStates(&project6_model_rtM->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++project6_model_rtM->Timing.clockTick0)) {
    ++project6_model_rtM->Timing.clockTickH0;
  }

  project6_model_rtM->Timing.t[0] = rtsiGetSolverStopTime
    (&project6_model_rtM->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++project6_model_rtM->Timing.clockTick1)) {
      ++project6_model_rtM->Timing.clockTickH1;
    }

    project6_model_rtM->Timing.t[1] = project6_model_rtM->Timing.clockTick1 *
      project6_model_rtM->Timing.stepSize1 +
      project6_model_rtM->Timing.clockTickH1 *
      project6_model_rtM->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void project6_model_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator1' */
  ((StateDerivatives_project6_model *) project6_model_rtM->ModelData.derivs)
    ->Integrator1_CSTATE = project6_model_B.ErrorSignal;
}

/* Model initialize function */
void project6_model_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = project6_model_rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = project6_model_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s3"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s1"),
          "Setpoint        %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s2"),
          "Motor Position  %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s3"),
          "Error Signal    %3.2f");
        rl32eSetScope(3, 4, 200);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Gain/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 170.0);
        xpceScopeAcqOK(3, &project6_model_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 4, 500);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -5.0);
        rl32eSetTargetScope(2, 10, 5.0);
        xpceScopeAcqOK(2, &project6_model_DWork.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo(
          "angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"));
        rl32eSetScope(4, 4, 500);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 10);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo(
          "angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 3.0);
        rl32eSetTargetScope(4, 11, -180.0);
        rl32eSetTargetScope(4, 10, 180.0);
        xpceScopeAcqOK(4, &project6_model_DWork.SFunction_IWORK_a.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 4, 500);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, -180.0);
        rl32eSetTargetScope(1, 10, 180.0);
        xpceScopeAcqOK(1, &project6_model_DWork.SFunction_IWORK_aj.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  project6_model_X.Integrator1_CSTATE = project6_model_P.Integrator1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  project6_model_DWork.Derivative1_RWORK.TimeStampA = rtInf;
  project6_model_DWork.Derivative1_RWORK.TimeStampB = rtInf;
}

/* Model terminate function */
void project6_model_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = project6_model_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = project6_model_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  project6_model_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  project6_model_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  project6_model_initialize();
}

void MdlTerminate(void)
{
  project6_model_terminate();
}

rtModel_project6_model *project6_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)project6_model_rtM, 0,
                sizeof(rtModel_project6_model));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&project6_model_rtM->solverInfo,
                          &project6_model_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&project6_model_rtM->solverInfo, &rtmGetTPtr(project6_model_rtM));
    rtsiSetStepSizePtr(&project6_model_rtM->solverInfo,
                       &project6_model_rtM->Timing.stepSize0);
    rtsiSetdXPtr(&project6_model_rtM->solverInfo,
                 &project6_model_rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&project6_model_rtM->solverInfo,
                         &project6_model_rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&project6_model_rtM->solverInfo,
      &project6_model_rtM->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&project6_model_rtM->solverInfo, (&rtmGetErrorStatus
      (project6_model_rtM)));
    rtsiSetRTModelPtr(&project6_model_rtM->solverInfo, project6_model_rtM);
  }

  rtsiSetSimTimeStep(&project6_model_rtM->solverInfo, MAJOR_TIME_STEP);
  project6_model_rtM->ModelData.intgData.y = project6_model_rtM->ModelData.odeY;
  project6_model_rtM->ModelData.intgData.f[0] =
    project6_model_rtM->ModelData.odeF[0];
  project6_model_rtM->ModelData.intgData.f[1] =
    project6_model_rtM->ModelData.odeF[1];
  project6_model_rtM->ModelData.intgData.f[2] =
    project6_model_rtM->ModelData.odeF[2];
  project6_model_rtM->ModelData.contStates = ((real_T *) &project6_model_X);
  rtsiSetSolverData(&project6_model_rtM->solverInfo, (void *)
                    &project6_model_rtM->ModelData.intgData);
  rtsiSetSolverName(&project6_model_rtM->solverInfo,"ode3");
  project6_model_rtM->solverInfoPtr = (&project6_model_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = project6_model_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    project6_model_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    project6_model_rtM->Timing.sampleTimes =
      (&project6_model_rtM->Timing.sampleTimesArray[0]);
    project6_model_rtM->Timing.offsetTimes =
      (&project6_model_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    project6_model_rtM->Timing.sampleTimes[0] = (0.0);
    project6_model_rtM->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    project6_model_rtM->Timing.offsetTimes[0] = (0.0);
    project6_model_rtM->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(project6_model_rtM, &project6_model_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = project6_model_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    project6_model_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(project6_model_rtM, -1);
  project6_model_rtM->Timing.stepSize0 = 0.0001;
  project6_model_rtM->Timing.stepSize1 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    project6_model_rtM->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(project6_model_rtM->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(project6_model_rtM->rtwLogInfo, (NULL));
    rtliSetLogT(project6_model_rtM->rtwLogInfo, "");
    rtliSetLogX(project6_model_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(project6_model_rtM->rtwLogInfo, "");
    rtliSetSigLog(project6_model_rtM->rtwLogInfo, "");
    rtliSetLogVarNameModifier(project6_model_rtM->rtwLogInfo, "rt_");
    rtliSetLogFormat(project6_model_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(project6_model_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(project6_model_rtM->rtwLogInfo, 1);
    rtliSetLogY(project6_model_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(project6_model_rtM->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(project6_model_rtM->rtwLogInfo, (NULL));
  }

  /* External mode info */
  project6_model_rtM->Sizes.checksums[0] = (129339729U);
  project6_model_rtM->Sizes.checksums[1] = (1760856200U);
  project6_model_rtM->Sizes.checksums[2] = (2524941749U);
  project6_model_rtM->Sizes.checksums[3] = (2094873264U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    project6_model_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(project6_model_rtM->extModeInfo,
      &project6_model_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(project6_model_rtM->extModeInfo,
                        project6_model_rtM->Sizes.checksums);
    rteiSetTPtr(project6_model_rtM->extModeInfo, rtmGetTPtr(project6_model_rtM));
  }

  project6_model_rtM->solverInfoPtr = (&project6_model_rtM->solverInfo);
  project6_model_rtM->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&project6_model_rtM->solverInfo, 0.0001);
  rtsiSetSolverMode(&project6_model_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  project6_model_rtM->ModelData.blockIO = ((void *) &project6_model_B);
  (void) memset(((void *) &project6_model_B), 0,
                sizeof(BlockIO_project6_model));

  /* parameters */
  project6_model_rtM->ModelData.defaultParam = ((real_T *)&project6_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &project6_model_X;
    project6_model_rtM->ModelData.contStates = (x);
    (void) memset((void *)&project6_model_X, 0,
                  sizeof(ContinuousStates_project6_model));
  }

  /* states (dwork) */
  project6_model_rtM->Work.dwork = ((void *) &project6_model_DWork);
  (void) memset((void *)&project6_model_DWork, 0,
                sizeof(D_Work_project6_model));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    project6_model_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    project6_model_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  project6_model_InitializeDataMapInfo(project6_model_rtM);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &project6_model_rtM->NonInlinedSFcns.sfcnInfo;
    project6_model_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(project6_model_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &project6_model_rtM->Sizes.numSampTimes);
    project6_model_rtM->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (project6_model_rtM)[0]);
    project6_model_rtM->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (project6_model_rtM)[1]);
    rtssSetTPtrPtr(sfcnInfo,project6_model_rtM->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(project6_model_rtM));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(project6_model_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (project6_model_rtM));
    rtssSetStepSizePtr(sfcnInfo, &project6_model_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(project6_model_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &project6_model_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &project6_model_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &project6_model_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &project6_model_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &project6_model_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &project6_model_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &project6_model_rtM->solverInfoPtr);
  }

  project6_model_rtM->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&project6_model_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    project6_model_rtM->childSfunctions =
      (&project6_model_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);
    project6_model_rtM->childSfunctions[0] =
      (&project6_model_rtM->NonInlinedSFcns.childSFunctions[0]);
    project6_model_rtM->childSfunctions[1] =
      (&project6_model_rtM->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: project6_model/<Root>/Channel 0 of  Encoder Inputs  (encquanserq8) */
    {
      SimStruct *rts = project6_model_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = project6_model_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = project6_model_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = project6_model_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &project6_model_rtM->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, project6_model_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &project6_model_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &project6_model_rtM->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &project6_model_rtM->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &project6_model_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &project6_model_B.Channel0ofEncoderInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "Channel 0 of \nEncoder Inputs ");
      ssSetPath(rts, "project6_model/Channel 0 of  Encoder Inputs ");
      ssSetRTModel(rts,project6_model_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &project6_model_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P10_Siz);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P11_Siz);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       project6_model_P.Channel0ofEncoderInputs_P12_Siz);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &project6_model_DWork.Channel0ofEncoderInputs_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &project6_model_rtM->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &project6_model_rtM->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &project6_model_DWork.Channel0ofEncoderInputs_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: project6_model/<Root>/Channel 0 -Control signal to  motor through amplifier  (daquanserq8) */
    {
      SimStruct *rts = project6_model_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = project6_model_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = project6_model_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = project6_model_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &project6_model_rtM->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, project6_model_rtM->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &project6_model_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &project6_model_rtM->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &project6_model_rtM->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &project6_model_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &project6_model_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &project6_model_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &project6_model_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &project6_model_P.Darknesssetpoint_Value;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "Channel 0 -Control signal to \nmotor through amplifier ");
      ssSetPath(rts,
                "project6_model/Channel 0 -Control signal to  motor through amplifier ");
      ssSetRTModel(rts,project6_model_rtM);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &project6_model_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotorthr);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_a);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_l);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_b);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_f);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotor_pp);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_h);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotort_d);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       project6_model_P.Channel0Controlsignaltomotor_np);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &project6_model_DWork.Channel0Controlsignaltomotorthr[0]);
      ssSetIWork(rts, (int_T *)
                 &project6_model_DWork.Channel0Controlsignaltomotort_j);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &project6_model_rtM->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &project6_model_rtM->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &project6_model_DWork.Channel0Controlsignaltomotorthr[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &project6_model_DWork.Channel0Controlsignaltomotort_j);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  project6_model_rtM->Sizes.numContStates = (1);/* Number of continuous states */
  project6_model_rtM->Sizes.numY = (0);/* Number of model outputs */
  project6_model_rtM->Sizes.numU = (0);/* Number of model inputs */
  project6_model_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  project6_model_rtM->Sizes.numSampTimes = (2);/* Number of sample times */
  project6_model_rtM->Sizes.numBlocks = (20);/* Number of blocks */
  project6_model_rtM->Sizes.numBlockIO = (12);/* Number of block outputs */
  project6_model_rtM->Sizes.numBlockPrms = (78);/* Sum of parameter "widths" */
  return project6_model_rtM;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
