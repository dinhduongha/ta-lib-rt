/* TA-LIB Copyright (c) 1999-2008, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*********************************************************************
 * This file contains only TA functions starting with the letter 'R' *
 *********************************************************************/
#include <stddef.h>
#include "ta_abstract.h"
#include "ta_def_ui.h"

/* Follow the 3 steps defined below for adding a new TA Function to this
 * file.
 */

/****************************************************************************
 * Step 1 - Define here the interface to your TA functions with
 *          the macro DEF_FUNCTION.
 *
 ****************************************************************************/

/* ROC BEGIN */
static const TA_InputParameterInfo    *TA_ROC_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_ROC_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_ROC_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_10,
  NULL
};

static const TA_InputParameterInfo *TA_ROC_StructParams[] = { NULL }; 

DEF_FUNCTION( ROC,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Rate of change : ((price/prevPrice)-1)*100", /* hint */
              "Roc",            /* CamelCase name */
              0                 /* flags */
             );
/* ROC END */

/* ROCP BEGIN */
static const TA_InputParameterInfo    *TA_ROCP_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_ROCP_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_ROCP_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_10,
  NULL
};

static const TA_InputParameterInfo *TA_ROCP_StructParams[] = { NULL }; 

DEF_FUNCTION( ROCP,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Rate of change Percentage: (price-prevPrice)/prevPrice", /* hint */
              "RocP",           /* CamelCase name */
              0                 /* flags */
             );
/* ROCP END */

/* ROCR BEGIN */
static const TA_InputParameterInfo    *TA_ROCR_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_ROCR_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_ROCR_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_10,
  NULL
};

static const TA_InputParameterInfo *TA_ROCR_StructParams[] = { NULL }; 

DEF_FUNCTION( ROCR,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Rate of change ratio: (price/prevPrice)", /* hint */
              "RocR",           /* CamelCase name */
              0                 /* flags */
             );
/* ROCR END */

/* ROCR100 BEGIN */
static const TA_InputParameterInfo    *TA_ROCR100_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_ROCR100_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_ROCR100_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_10,
  NULL
};

static const TA_InputParameterInfo *TA_ROCR100_StructParams[] = { NULL }; 

DEF_FUNCTION( ROCR100,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Rate of change ratio 100 scale: (price/prevPrice)*100", /* hint */
              "RocR100",       /* CamelCase name */
              0                /* flags */
             );
/* ROCR100 END */

/* RSI BEGIN */
static const TA_InputParameterInfo    *TA_RSI_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_RSI_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_RSI_OptInputs[] =
{
  &TA_DEF_UI_TimePeriod_14_MINIMUM2,
  NULL
};

const TA_InputParameterInfo TA_RSI_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Integer, "MetastockMode", 0 };
const TA_InputParameterInfo TA_RSI_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "prevGain", 0 };
const TA_InputParameterInfo TA_RSI_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Real, "prevLoss", 0 };
const TA_InputParameterInfo TA_RSI_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Real, "prevValue", 0 };

static const TA_InputParameterInfo *TA_RSI_StructParams[] = {
    &TA_RSI_DEF_UI_STRUCT_PARAM_1,
    &TA_RSI_DEF_UI_STRUCT_PARAM_2,
    &TA_RSI_DEF_UI_STRUCT_PARAM_3,
    &TA_RSI_DEF_UI_STRUCT_PARAM_4,
    NULL };

DEF_FUNCTION( RSI,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Relative Strength Index",  /* hint */
              "Rsi",                      /* CamelCase name */
              TA_FUNC_FLG_UNST_PER        /* flags */
             );
/* RSI END */

/* REDK_EVEREX BEGIN */
static const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_ROF_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInRofPeriod", /* paramName */
   0,                  /* flags */

   "Rate of Flow Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   10, /* defaultValue */
   "Rate of Flow Period", /* hint */
   NULL /* CamelCase name */
};

const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_ROF_MA_Method =
{
   TA_OptInput_IntegerList, /* type */
   "optInRofMAType",           /* paramName */
   0,                       /* flags */

   "ROF MA Type",                /* displayName */
   (const void *)&TA_MA_TypeList, /* dataSet */
   2, /* defaultValue = WMA */
   "Type of ROF Moving Average", /* hint */

   NULL /* helpFile */
};

static const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_ROF_Smooth =
{
   TA_OptInput_RealRange, /* type */
   "optInRofSmooth", /* paramName */
   0,                  /* flags */

   "Rate of Flow Period",          /* displayName */
   (const void *)&TA_DEF_RealPositive, /* dataSet */
   3.0, /* defaultValue */
   "Rate of Flow Smooth", /* hint */
   NULL /* CamelCase name */
};

static const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_Signal_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInSignalPeriod", /* paramName */
   0,                  /* flags */

   "Signal Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   5, /* defaultValue */
   "Signal Period", /* hint */
   NULL /* CamelCase name */
};

const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_Signal_MA_Method =
{
   TA_OptInput_IntegerList, /* type */
   "optInSignalMAType",           /* paramName */
   0,                       /* flags */

   "Signal MA Type",                /* displayName */
   (const void *)&TA_MA_TypeList, /* dataSet */
   2, /* defaultValue = WMA */
   "Type of Signal Moving Average", /* hint */

   NULL /* helpFile */
};


static const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_BiasSentiment_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInBiasPeriod", /* paramName */
   0,                  /* flags */

   "Bias Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   30, /* defaultValue */
   "Bias Period", /* hint */
   NULL /* CamelCase name */
};

const TA_OptInputParameterInfo TA_DEF_UI_REDK_EVEREX_BiasSentiment_MA_Method =
{
   TA_OptInput_IntegerList, /* type */
   "optInBiasMAType",           /* paramName */
   0,                       /* flags */

   "Bias MA Type",                /* displayName */
   (const void *)&TA_MA_TypeList, /* dataSet */
   2, /* defaultValue = WMA */
   "Type of Bias Moving Average", /* hint */

   NULL /* helpFile */
};

static const TA_InputParameterInfo *TA_REDK_EVEREX_Inputs[] =
{
  &TA_DEF_UI_Input_Price_OHLCV,
  NULL
};

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_VolumeNormalized =
                               { TA_Output_Real, "outVolNorm", TA_OUT_LINE }; // nVol

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_PriceNormalized =
                               { TA_Output_Real, "outPriceNorm", TA_OUT_LINE }; // nPrice

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Flow =
                               { TA_Output_Real, "outFlow", TA_OUT_LINE }; // Bar flow

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_BullAvg =
                               { TA_Output_Real, "outBullAvg", TA_OUT_LINE }; // ta.wma(bulls_avg, smooth)

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_BearAvg =
                               { TA_Output_Real, "outBearAvg", TA_OUT_LINE }; // ta.wma(bears_avg, smooth)

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Rof =
                               { TA_Output_Real, "outRROF", TA_OUT_LINE }; // RROF

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_RofSmooth =
                               { TA_Output_Real, "outRROFSmooth", TA_OUT_LINE }; // RROF_s RROF Smooth

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Signal =
                               { TA_Output_Real, "outSignal", TA_OUT_LINE }; // Signal

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_BiasSentiment =
                               { TA_Output_Real, "outBiasSentiment", TA_OUT_LINE }; // RROF_b

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_BiasSentimentSmooth =
                               { TA_Output_Real, "outBiasSentimentSmooth", TA_OUT_LINE }; // RROF_bs

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Ev_Ratio =
                               { TA_Output_Real, "outEvRatio", TA_OUT_LINE }; // Ev Ratio: 100 * nPrice_abs / nVol

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Flow_Up =
                               { TA_Output_Integer, "outFlowUp", TA_OUT_LINE }; // Is bar up, vol up, price up

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Positive =
                               { TA_Output_Integer, "outPositive", TA_OUT_LINE }; // Is vol up

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Compression =
                               { TA_Output_Integer, "outCompression", TA_OUT_LINE }; // Is compression up

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_REDK_EVEREX_Eom =
                               { TA_Output_Integer, "outEoM", TA_OUT_LINE }; // Is Easy of Move


static const TA_OutputParameterInfo *TA_REDK_EVEREX_Outputs[]   =
{
  &TA_DEF_UI_Output_Real_REDK_EVEREX_VolumeNormalized,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_PriceNormalized,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_Flow,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_BullAvg,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_BearAvg,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_Rof,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_RofSmooth,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_Signal,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_BiasSentiment,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_BiasSentimentSmooth,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_Ev_Ratio,
  &TA_DEF_UI_Output_Real_REDK_EVEREX_Flow_Up,
  NULL
};

static const TA_OptInputParameterInfo *TA_REDK_EVEREX_OptInputs[] = {
  &TA_DEF_UI_TimePeriod_30, // Lookback
  &TA_DEF_UI_MA_Method,     // Lookback Averaging
  &TA_DEF_UI_REDK_EVEREX_ROF_Period,
  &TA_DEF_UI_REDK_EVEREX_ROF_MA_Method,
  &TA_DEF_UI_REDK_EVEREX_ROF_Smooth,
  &TA_DEF_UI_REDK_EVEREX_Signal_Period,
  &TA_DEF_UI_REDK_EVEREX_Signal_MA_Method,
  &TA_DEF_UI_REDK_EVEREX_BiasSentiment_Period,
  &TA_DEF_UI_REDK_EVEREX_BiasSentiment_MA_Method,
  NULL };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Pointer, "StateVolMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Pointer, "StateBarSpreadMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Pointer, "StateSrcShiftMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Pointer, "StateBullMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_5 =
                                  { TA_Input_Pointer, "StateBearMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_6 =
                                  { TA_Input_Pointer, "StateRrofMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_7 =
                                  { TA_Input_Pointer, "StateRrofSmootMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_8 =
                                  { TA_Input_Pointer, "StateSignalMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_9 =
                                  { TA_Input_Pointer, "StateBiasBullMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_10 =
                                  { TA_Input_Pointer, "StateBiasBearMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_11 =
                                  { TA_Input_Pointer, "StateBiasSmoothMA", 0 };

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_12 =
                                  { TA_Input_Pointer, "StateBullSmoothWMA", 0 }; // Bull avg smooth

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_13 =
                                  { TA_Input_Pointer, "StateBearSmoothWMA", 0 }; // Bear avg smooth

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_14 =
                                  { TA_Input_Pointer, "StateBullMax", 0 }; // 

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_15 =
                                  { TA_Input_Pointer, "StateBearMin", 0 }; // 

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_16 =
                                  { TA_Input_Pointer, "StateMinPriceN", 0 }; // 

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_17 =
                                  { TA_Input_Pointer, "StateMaxNPrice", 0 }; // 

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_18 =
                                  { TA_Input_Pointer, "StateMinVolN", 0 }; // Min Volume Normalized

const TA_InputParameterInfo TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_19 =
                                  { TA_Input_Pointer, "StateMaxNVol", 0 }; // Bear avg smooth


static const TA_InputParameterInfo *TA_REDK_EVEREX_StructParams[] = {
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_1,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_2,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_3,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_4,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_5,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_6,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_7,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_8,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_9,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_10,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_11,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_12,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_13,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_14,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_15,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_16,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_17,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_18,
  &TA_REDK_EVEREX_DEF_UI_STRUCT_PARAM_19,
  NULL };

DEF_FUNCTION( REDK_EVEREX,                     /* name */
              TA_GroupId_OverlapStudies, /* groupId */
              "RedK EVEREX - Effort Versus Results Explorer", /* hint */
              "RedkEverex",                         /* CamelCase name */
              0                              /* flags */
             );
/* REDK_EVEREX END */

/****************************************************************************
 * Step 2 - Add your TA function to the table.
 *          Keep in alphabetical order. Must be NULL terminated.
 ****************************************************************************/
const TA_FuncDef *TA_DEF_TableR[] =
{
   ADD_TO_TABLE(REDK_EVEREX),
   ADD_TO_TABLE(ROC),
   ADD_TO_TABLE(ROCP),
   ADD_TO_TABLE(ROCR),
   ADD_TO_TABLE(ROCR100),
   ADD_TO_TABLE(RSI),
   NULL
};


/* Do not modify the following line. */
const unsigned int TA_DEF_TableRSize =
              ((sizeof(TA_DEF_TableR)/sizeof(TA_FuncDef *))-1);


/****************************************************************************
 * Step 3 - Make sure "gen_code" is executed for generating all other
 *          source files derived from this one.
 *          You can then re-compile the library as usual and you are done!
 ****************************************************************************/
