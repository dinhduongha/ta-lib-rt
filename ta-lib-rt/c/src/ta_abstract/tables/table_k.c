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
 * This file contains only TA functions starting with the letter 'K' *
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

/* KAMA BEGIN */
static const TA_InputParameterInfo    *TA_KAMA_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_KAMA_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_KAMA_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_30,
  NULL
};

const TA_InputParameterInfo TA_KAMA_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Real, "sumROC1", 0 };
const TA_InputParameterInfo TA_KAMA_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "yestReal", 0 };
const TA_InputParameterInfo TA_KAMA_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Real, "prevKAMA", 0 };
const TA_InputParameterInfo TA_KAMA_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Real, "trailingValue", 0 };

static const TA_InputParameterInfo *TA_KAMA_StructParams[] = {
    &TA_KAMA_DEF_UI_STRUCT_PARAM_1,
    &TA_KAMA_DEF_UI_STRUCT_PARAM_2,
    &TA_KAMA_DEF_UI_STRUCT_PARAM_3,
    &TA_KAMA_DEF_UI_STRUCT_PARAM_4,
    NULL };

DEF_FUNCTION( KAMA,                     /* name */
              TA_GroupId_OverlapStudies,  /* groupId */
              "Kaufman Adaptive Moving Average", /* hint */
              "Kama",                       /* CamelCase name */
              TA_FUNC_FLG_OVERLAP|TA_FUNC_FLG_UNST_PER        /* flags */
             );
/* KAMA END */

/* KVO BEGIN */
static const TA_RealRange TA_DEF_KVO_Value =
{
   TA_REAL_MIN, /* min */
   TA_REAL_MAX, /* max */
   4,     /* precision */
   0, /* suggested start */
   0, /* suggested end   */
   0  /* suggested increment */
};
static const TA_OptInputParameterInfo TA_DEF_UI_KVO_Modifier =
{
   TA_OptInput_RealRange, /* type */
   "optInModifier", /* paramName */
   0,                  /* flags */

   "Modifier",          /* displayName */
   (const void *)&TA_DEF_KVO_Value, /* dataSet */
   1.0, /* defaultValue */
   "Modifier", /* hint */
   NULL /* CamelCase name */
};
static const TA_InputParameterInfo *TA_KVO_Inputs[] =
{
  &TA_DEF_UI_Input_Price_HLCV,
  NULL
};

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_KVO =
                               { TA_Output_Real, "outKVO", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_KVO_Signal =
                               { TA_Output_Real, "outKVOSignal", TA_OUT_LINE };

static const TA_OutputParameterInfo *TA_KVO_Outputs[]   =
{
  &TA_DEF_UI_Output_Real_KVO,
  &TA_DEF_UI_Output_Real_KVO_Signal,
  NULL
};

static const TA_OptInputParameterInfo *TA_KVO_OptInputs[] =
{ &TA_DEF_UI_Fast_Period,
  &TA_DEF_UI_Slow_Period,
  &TA_DEF_UI_Input_Periods,
  &TA_DEF_UI_MA_Method,
  NULL
};

const TA_InputParameterInfo TA_KVO_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Pointer, "StateMAFast", 0 };

const TA_InputParameterInfo TA_KVO_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Pointer, "StateMASlow", 0 };

const TA_InputParameterInfo TA_KVO_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Pointer, "StateMASignal", 0 };

static const TA_InputParameterInfo *TA_KVO_StructParams[] = {
  &TA_KVO_DEF_UI_STRUCT_PARAM_1,
  &TA_KVO_DEF_UI_STRUCT_PARAM_2,
  &TA_KVO_DEF_UI_STRUCT_PARAM_3,
  NULL };

DEF_FUNCTION( KVO,                     /* name */
              TA_GroupId_VolatilityIndicators, /* groupId */
              "Klinger Volume Oscillator", /* hint */
              "Kvo",                         /* CamelCase name */
              TA_FUNC_FLG_UNST_PER            /* flags */
             );
/* KVO END */

/****************************************************************************
 * Step 2 - Add your TA function to the table.
 *          Keep in alphabetical order. Must be NULL terminated.
 ****************************************************************************/
const TA_FuncDef *TA_DEF_TableK[] =
{
   ADD_TO_TABLE(KAMA),
   NULL
};


/* Do not modify the following line. */
const unsigned int TA_DEF_TableKSize =
              ((sizeof(TA_DEF_TableK)/sizeof(TA_FuncDef *))-1);


/****************************************************************************
 * Step 3 - Make sure "gen_code" is executed for generating all other
 *          source files derived from this one.
 *          You can then re-compile the library as usual and you are done!
 ****************************************************************************/
