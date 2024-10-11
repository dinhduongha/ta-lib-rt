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
 * This file contains only TA functions starting with the letter 'V' *
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

/* VAR BEGIN */
static const TA_InputParameterInfo    *TA_VAR_Inputs[]    =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo   *TA_VAR_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_VAR_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_5,
  &TA_DEF_UI_NbDeviation,
  NULL
};

const TA_InputParameterInfo TA_VAR_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Real, "periodTotal1", 0 };
const TA_InputParameterInfo TA_VAR_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "periodTotal2", 0 };

static const TA_InputParameterInfo *TA_VAR_StructParams[] = {
    &TA_VAR_DEF_UI_STRUCT_PARAM_1,
    &TA_VAR_DEF_UI_STRUCT_PARAM_2,
    NULL };

DEF_FUNCTION( VAR,                         /* name */
              TA_GroupId_Statistic,     /* groupId */
              "Variance",               /* hint */
              "Variance",               /* CamelCase name */
              0                         /* flags */
             );
/* VAR END */

/* VROC BEGIN */
static const TA_InputParameterInfo *TA_VROC_Inputs[] =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo *TA_VROC_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_VROC_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_10,
  NULL
};

static const TA_InputParameterInfo *TA_VROC_StructParams[] = { NULL };

DEF_FUNCTION( VROC,                     /* name */
              TA_GroupId_VolumeIndicators, /* groupId */
              "Volume Rate of Change", /* hint */
              "Vroc",                         /* CamelCase name */
              0                              /* flags */
             );
/* VROC END */

/* VP BEGIN */
// https://www.quantconnect.com/forum/discussion/10590/volume-profile-indicator-implementation-in-c/
static const TA_OptInputParameterInfo TA_DEF_UI_VP_Width =
{
   TA_OptInput_IntegerRange, /* type */
   "optInVpWidth", /* paramName */
   0,                  /* flags */

   "Width",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   10, /* defaultValue */
   "Width", /* hint */
   NULL /* CamelCase name */
};


static const TA_InputParameterInfo *TA_VP_Inputs[] =
{
  &TA_DEF_UI_Input_Price_CV,
  NULL
};

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_VP_Poc =
                               { TA_Output_Real, "outPoc", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_VP_Vah =
                               { TA_Output_Real, "outVaHigh", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_VP_Val =
                               { TA_Output_Real, "outVaLow", TA_OUT_LINE };

static const TA_OutputParameterInfo *TA_VP_Outputs[]   =
{
  &TA_DEF_UI_Output_Real_VP_Poc,
  &TA_DEF_UI_Output_Real_VP_Vah,
  &TA_DEF_UI_Output_Real_VP_Val,
  &TA_DEF_UI_Output_Real,
  &TA_DEF_UI_Output_Integer,
  NULL
};

static const TA_OptInputParameterInfo *TA_VP_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_30, // Lookback
  &TA_DEF_UI_VP_Width,
  NULL
};

const TA_InputParameterInfo TA_VP_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Pointer, "stateMINMAX", 0 };

const TA_InputParameterInfo TA_VP_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Pointer, "stateSumVolume", 0 };

const TA_InputParameterInfo TA_VP_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Pointer, "stateSumUpVolume", 0 };

const TA_InputParameterInfo TA_VP_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Pointer, "stateSumDownVolume", 0 };

static const TA_InputParameterInfo *TA_VP_StructParams[] = {
  &TA_VP_DEF_UI_STRUCT_PARAM_1,
  NULL };

DEF_FUNCTION( VP,                     /* name */
              TA_GroupId_VolumeIndicators, /* groupId */
              "Volume Profile", /* hint */
              "Vp",                         /* CamelCase name */
              0                              /* flags */
             );
/* VP END */

/* VWAP BEGIN */
static const TA_InputParameterInfo *TA_VWAP_Inputs[] =
{
  &TA_DEF_UI_Input_Price_HLCV,
  NULL
};

static const TA_OutputParameterInfo *TA_VWAP_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_VWAP_OptInputs[] = 
{ &TA_DEF_UI_TimePeriod_10,
  NULL 
};

const TA_InputParameterInfo TA_VWAP_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Pointer, "StateSumTPV", 0 }; // Total TypicalPrice*Volume

const TA_InputParameterInfo TA_VWAP_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Pointer, "StateSumVolume", 0 };

static const TA_InputParameterInfo *TA_VWAP_StructParams[] = { NULL };

DEF_FUNCTION( VWAP,                     /* name */
              TA_GroupId_VolumeIndicators, /* groupId */
              "Volume Weighted Average Price", /* hint */
              "Vwap",                         /* CamelCase name */
              0                              /* flags */
             );
/* VWAP END */

/* VWMA BEGIN */
static const TA_InputParameterInfo *TA_VWMA_Inputs[] =
{
  &TA_DEF_UI_Input_Real,
  NULL
};

static const TA_OutputParameterInfo *TA_VWMA_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_VWMA_OptInputs[] =
{ &TA_DEF_UI_TimePeriod_30,
  NULL
};

const TA_InputParameterInfo TA_VWMA_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Real, "periodSum", 0 };
const TA_InputParameterInfo TA_VWMA_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "periodSub", 0 };
const TA_InputParameterInfo TA_VWMA_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Real, "divider", 0 };

static const TA_InputParameterInfo *TA_VWMA_StructParams[] = {
    &TA_VWMA_DEF_UI_STRUCT_PARAM_1,
    &TA_VWMA_DEF_UI_STRUCT_PARAM_2,
    &TA_VWMA_DEF_UI_STRUCT_PARAM_3,
    NULL };

DEF_FUNCTION( VWMA,                     /* name */
              TA_GroupId_VolumeIndicators, /* groupId */
              "Volume Weighted Moving Average", /* hint */
              "Vwma",                         /* CamelCase name */
              0                              /* flags */
             );
/* VWMA END */

/****************************************************************************
 * Step 2 - Add your TA function to the table.
 *          Keep in alphabetical order. Must be NULL terminated.
 ****************************************************************************/
const TA_FuncDef *TA_DEF_TableV[] =
{
   ADD_TO_TABLE(VAR),
   ADD_TO_TABLE(VROC),
   ADD_TO_TABLE(VP),
   ADD_TO_TABLE(VWAP),
   ADD_TO_TABLE(VWMA),
   NULL
};


/* Do not modify the following line. */
const unsigned int TA_DEF_TableVSize =
              ((sizeof(TA_DEF_TableV)/sizeof(TA_FuncDef *))-1);


/****************************************************************************
 * Step 3 - Make sure "gen_code" is executed for generating all other
 *          source files derived from this one.
 *          You can then re-compile the library as usual and you are done!
 ****************************************************************************/
