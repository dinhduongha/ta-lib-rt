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
 * This file contains only TA functions starting with the letter 'E' *
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

/* EMA BEGIN */
static const TA_InputParameterInfo    *TA_EMA_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_EMA_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_EMA_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_30,
  NULL
};

const TA_InputParameterInfo TA_EMA_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Real, "prevMA", 0 };

const TA_InputParameterInfo TA_EMA_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "tempSum", 0 };

const TA_InputParameterInfo TA_EMA_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Real, "preprRes", 0 };

const TA_InputParameterInfo TA_EMA_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Real, "optInK_1", 0 };

static const TA_InputParameterInfo *TA_EMA_StructParams[] = {
    &TA_EMA_DEF_UI_STRUCT_PARAM_1,
    &TA_EMA_DEF_UI_STRUCT_PARAM_2,
    &TA_EMA_DEF_UI_STRUCT_PARAM_3,
    &TA_EMA_DEF_UI_STRUCT_PARAM_4,
    NULL };

DEF_FUNCTION( EMA,                         /* name */
              TA_GroupId_OverlapStudies,  /* groupId */
              "Exponential Moving Average", /* hint */
              "Ema",                       /* CamelCase name */
              TA_FUNC_FLG_OVERLAP|TA_FUNC_FLG_UNST_PER /* flags */
             );
/* EMA END */

/* EOM BEGIN */
static const TA_OptInputParameterInfo TA_DEF_UI_EOM_Divisor =
{
   TA_OptInput_IntegerRange, /* type */
   "optInDivisor", /* paramName */
   0,                  /* flags */

   "Divisor",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   10000, /* defaultValue */
   "Divisor", /* hint */
   NULL /* CamelCase name */
};

static const TA_InputParameterInfo *TA_EOM_Inputs[] =
{
  &TA_DEF_UI_Input_Price_HLCV,
  NULL
};

static const TA_OutputParameterInfo *TA_EOM_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_EOM_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_14, // Period
  &TA_DEF_UI_MA_Method,
  &TA_DEF_UI_EOM_Divisor,
  NULL
};

const TA_InputParameterInfo TA_EOM_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Pointer, "StateSMA", 0 };

const TA_InputParameterInfo TA_EOM_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "prevHigh", 0 };

const TA_InputParameterInfo TA_EOM_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Real, "prevLow", 0 };                                                                    

static const TA_InputParameterInfo *TA_EOM_StructParams[] = {
  &TA_EOM_DEF_UI_STRUCT_PARAM_1,
  &TA_EOM_DEF_UI_STRUCT_PARAM_2,
  &TA_EOM_DEF_UI_STRUCT_PARAM_3,
  NULL };

DEF_FUNCTION( EOM,                     /* name */
              TA_GroupId_VolatilityIndicators, /* groupId */
              "Ease of Movement", /* hint */
              "Emv",                         /* CamelCase name */
              TA_FUNC_FLG_UNST_PER            /* flags */
             );
/* EOM END */

/* EXP BEGIN */
DEF_MATH_UNARY_OPERATOR( EXP, "Vector Arithmetic Exp", "Exp" )
/* EXP END */

/****************************************************************************
 * Step 2 - Add your TA function to the table.
 *          Keep in alphabetical order. Must be NULL terminated.
 ****************************************************************************/
const TA_FuncDef *TA_DEF_TableE[] =
{
   ADD_TO_TABLE(EMA),
   ADD_TO_TABLE(EOM),
   ADD_TO_TABLE(EXP),
   NULL
};


/* Do not modify the following line. */
const unsigned int TA_DEF_TableESize =
              ((sizeof(TA_DEF_TableE)/sizeof(TA_FuncDef *))-1);


/****************************************************************************
 * Step 3 - Make sure "gen_code" is executed for generating all other
 *          source files derived from this one.
 *          You can then re-compile the library as usual and you are done!
 ****************************************************************************/
