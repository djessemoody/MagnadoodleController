#ifndef __project6_model_XPCOPTIONS_H___
#define __project6_model_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "project6_model.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_project6_model))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            64
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0

/* Change all stepsize using the newBaseRateStepSize */
void project6_model_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_project6_model *const project6_model_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.0001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  project6_model_rtM->Timing.stepSize0 = project6_model_rtM->Timing.stepSize0 *
    ratio;
  project6_model_rtM->Timing.stepSize1 = project6_model_rtM->Timing.stepSize1 *
    ratio;
  project6_model_rtM->Timing.stepSize = project6_model_rtM->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  project6_model_ChangeStepSize(stepSize, project6_model_rtM);
}

#endif                                 /* __project6_model_XPCOPTIONS_H___ */
