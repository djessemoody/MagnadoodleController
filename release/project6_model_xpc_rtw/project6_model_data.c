/*
 * project6_model_data.c
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
#include "project6_model_private.h"

/* Block parameters (auto storage) */
Parameters_project6_model project6_model_P = {
  -15.0,                               /* Expression: -15
                                        * Referenced by: '<Root>/Angle setpoint'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/gain'
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P1_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P2_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P3_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P4_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P5_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: quadrature
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P6_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P7_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P8_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P9_Size
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P10_Siz
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P11_Siz
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P12_Siz
   * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Channel 0 of  Encoder Inputs '
                                        */
  0.225,                               /* Expression: 360/1600
                                        * Referenced by: '<Root>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                        */
  2.5,                                 /* Expression: 2.5
                                        * Referenced by: '<Root>/Kp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Kd'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Darkness setpoint'
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotorthr
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_a
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 3.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_l
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: range
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { -10.0, -10.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_b
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_f
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotor_pp
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_h
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0001,                              /* Expression: sampleTime
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_d
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_np
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
};
