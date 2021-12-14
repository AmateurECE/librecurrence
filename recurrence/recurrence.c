///////////////////////////////////////////////////////////////////////////////
// NAME:            recurrence.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Entrypoints for the library
//
// CREATED:         12/10/2021
//
// LAST EDITED:     12/13/2021
//
// Copyright 2021, Ethan D. Twardy
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
////

#include <stdlib.h>

#include <recurrence/recurrence.h>

// Opaque struct performing the workload of the library
typedef struct OccurrenceSeries {
    int unused;
} OccurrenceSeries;

typedef struct ParserInputContext {
    OccurrenceSeries* series;
    char* string;
    size_t length;
    size_t index;
} ParserInputContext;

static void series_monthly(OccurrenceSeries* series, char* text);
typedef struct _yycontext yycontext;
static void priv_recurrence_input(yycontext* context, char* buffer,
    int* result, int max_size);
#define YY_CTX_LOCAL 1
#define YY_INPUT(context, buffer, result, max_size)     \
    priv_recurrence_input(context, buffer, &result, max_size);
#define YY_CTX_MEMBERS ParserInputContext* input_context;
#include "recurrence-parser.h"

///////////////////////////////////////////////////////////////////////////////
// Private API
////

static void series_monthly(OccurrenceSeries* series, char* text) {
    printf("%s\n", text);
}

static void priv_recurrence_input(yycontext* context, char* buffer,
    int* result, int max_size)
{
    ParserInputContext* input = (ParserInputContext*)context->input_context;
    if (input->index >= input->length) {
        *result = 0;
        return;
    }

    size_t bytes_read = input->length - input->index;
    if (bytes_read > (size_t)max_size) {
        bytes_read = max_size;
    }

    strncpy(buffer, input->string + input->index, bytes_read);
    input->index += bytes_read;
    *result = bytes_read;
}

///////////////////////////////////////////////////////////////////////////////
// Public API
////

// Convert the human-readable series description in <description> to an
// OccurrenceSeries
OccurrenceSeries* recurrence_series_new(char* description) {
    OccurrenceSeries* series = malloc(sizeof(OccurrenceSeries));
    if (NULL == series) {
        return NULL;
    }

    ParserInputContext input_context = {
        .series = series,
        .string = description,
        .length = strlen(description),
        .index = 0,
    };

    yycontext context;
    memset(&context, 0, sizeof(yycontext));
    context.input_context = &input_context;
    while (yyparse(&context));

    yyrelease(&context);
    return series;
}

// Free internal memory used by an OccurrenceSeries
void recurrence_series_free(OccurrenceSeries** series) {
    if (NULL == *series) {
        return;
    }

    free(*series);
    *series = NULL;
}

// Canonicalize <occurrence> to the occurrence series <series>, rounding up or
// down to the nearest occurrence in the series based on <direction>.
time_t recurrence_canonicalize(time_t occurrence, OccurrenceSeries* series,
    enum RecurrenceRoundingDirection direction)
{ return (time_t)-1; }

// Return the next occurrence in the series <series>, whether <occurrence> is
// a canonical occurrence in <series> or not.
time_t recurrence_next_occurrence(time_t occurrence, OccurrenceSeries* series)
{ return (time_t)-1; }

///////////////////////////////////////////////////////////////////////////////
