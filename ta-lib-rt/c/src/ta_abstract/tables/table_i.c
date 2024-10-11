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
 * This file contains only TA functions starting with the letter 'I' *
 *********************************************************************/
#include <stddef.h>
#include "ta_abstract.h"
#include "ta_def_ui.h"

/* ICHIMOKU BEGIN */
static const TA_OptInputParameterInfo TA_DEF_UI_Conversion_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInConversionPeriod", /* paramName */
   0,                  /* flags */

   "Conversion Tenkan Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   9, /* defaultValue */
   "Conversion Tenkan Period", /* hint */
   NULL /* CamelCase name */
};

static const TA_OptInputParameterInfo TA_DEF_UI_Base_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInBasePeriod", /* paramName */
   0,                  /* flags */

   "Base Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   26, /* defaultValue */
   "Base Kijun Period", /* hint */
   NULL /* CamelCase name */
};

static const TA_OptInputParameterInfo TA_DEF_UI_Span_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInSpanPeriod", /* paramName */
   0,                  /* flags */

   "Span Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   52, /* defaultValue */
   "Span Senkou Period", /* hint */
   NULL /* CamelCase name */
};

static const TA_OptInputParameterInfo TA_DEF_UI_Chikou_Period =
{
   TA_OptInput_IntegerRange, /* type */
   "optInChikouPeriod", /* paramName */
   0,                  /* flags */

   "Chikou Period",          /* displayName */
   (const void *)&TA_DEF_TimePeriod_Positive, /* dataSet */
   26, /* defaultValue */
   "Chikou Period", /* hint */
   NULL /* CamelCase name */
};

static const TA_InputParameterInfo *TA_ICHIMOKU_Inputs[] =
{
  &TA_DEF_UI_Input_Price_HLC,
  NULL
};

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_ICHIMOKU_Tenkan =
                               { TA_Output_Real, "outTenkan", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_ICHIMOKU_Kijun =
                               { TA_Output_Real, "outKijun", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_ICHIMOKU_SenkouSpanA =
                               { TA_Output_Real, "outSenkouSpanA", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_ICHIMOKU_SenkouSpanB =
                               { TA_Output_Real, "outSenkouSpanB", TA_OUT_LINE };

const TA_OutputParameterInfo TA_DEF_UI_Output_Real_ICHIMOKU_ChikouSpan =
                               { TA_Output_Real, "outChikouSpan", TA_OUT_LINE };

static const TA_OutputParameterInfo *TA_ICHIMOKU_Outputs[]   =
{
  &TA_DEF_UI_Output_Real_ICHIMOKU_Tenkan,
  &TA_DEF_UI_Output_Real_ICHIMOKU_Kijun,
  &TA_DEF_UI_Output_Real_ICHIMOKU_SenkouSpanA,
  &TA_DEF_UI_Output_Real_ICHIMOKU_SenkouSpanB,
  &TA_DEF_UI_Output_Real_ICHIMOKU_ChikouSpan,
  NULL
};

static const TA_OptInputParameterInfo *TA_ICHIMOKU_OptInputs[] = {
  &TA_DEF_UI_Conversion_Period,
  &TA_DEF_UI_Base_Period,
  &TA_DEF_UI_Span_Period,
  &TA_DEF_UI_Chikou_Period,
  NULL };

const TA_InputParameterInfo TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Integer, "conversionPeriod", 9 };

const TA_InputParameterInfo TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Integer, "basePeriod", 26 };

const TA_InputParameterInfo TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_3 =
                                  { TA_Input_Integer, "spanPeriod", 52 };

const TA_InputParameterInfo TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_4 =
                                  { TA_Input_Integer, "displacement", 26 };

static const TA_InputParameterInfo *TA_ICHIMOKU_StructParams[] = {
  &TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_1,
  &TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_2,
  &TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_3,
  &TA_ICHIMOKU_DEF_UI_STRUCT_PARAM_4,
  NULL };

DEF_FUNCTION( ICHIMOKU,                     /* name */
              TA_GroupId_OverlapStudies, /* groupId */
              "Ichimoku Cloud", /* hint */
              "Ichimoku",                         /* CamelCase name */
              0                              /* flags */
             );
/* ICHIMOKU END */

/* Follow the 3 steps defined below for adding a new TA Function to this
 * file.
 */

/****************************************************************************
 * Step 1 - Define here the interface to your TA functions with
 *          the macro DEF_FUNCTION.
 *
 ****************************************************************************/

/* IMI BEGIN */
static const TA_InputParameterInfo    *TA_IMI_Inputs[]    =
{
  &TA_DEF_UI_Input_Price_OC,
  NULL
};

static const TA_OutputParameterInfo   *TA_IMI_Outputs[]   =
{
  &TA_DEF_UI_Output_Real,
  NULL
};

static const TA_OptInputParameterInfo *TA_IMI_OptInputs[] =
{
  &TA_DEF_UI_TimePeriod_14_MINIMUM2,
  NULL
};


const TA_InputParameterInfo TA_IMI_DEF_UI_STRUCT_PARAM_1 =
                                  { TA_Input_Real, "upsum", 0 };
const TA_InputParameterInfo TA_IMI_DEF_UI_STRUCT_PARAM_2 =
                                  { TA_Input_Real, "downsum", 0 };

static const TA_InputParameterInfo *TA_IMI_StructParams[] = {
    &TA_IMI_DEF_UI_STRUCT_PARAM_1,
    &TA_IMI_DEF_UI_STRUCT_PARAM_2,
    NULL };


DEF_FUNCTION( IMI,                         /* name */
              TA_GroupId_MomentumIndicators,  /* groupId */
              "Intraday Momentum Index",  /* hint */
              "Imi",                      /* CamelCase name */
              TA_FUNC_FLG_UNST_PER        /* flags */
             );

/* IMI END */

/****************************************************************************
 * Step 2 - Add your TA function to the table.
 *          Keep in alphabetical order. Must be NULL terminated.
 ****************************************************************************/
const TA_FuncDef *TA_DEF_TableI[] =
{
   ADD_TO_TABLE(IMI),
   ADD_TO_TABLE(ICHIMOKU),
   NULL
};


/* Do not modify the following line. */
const unsigned int TA_DEF_TableISize =
              ((sizeof(TA_DEF_TableI)/sizeof(TA_FuncDef *))-1);


/****************************************************************************
 * Step 3 - Make sure "gen_code" is executed for generating all other
 *          source files derived from this one.
 *          You can then re-compile the library as usual and you are done!
 ****************************************************************************/
