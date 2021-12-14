///////////////////////////////////////////////////////////////////////////////
// NAME:            recurrence.h
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Public interface for the API
//
// CREATED:         12/13/2021
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

#ifndef RECURRENCE_H
#define RECURRENCE_H

#include <time.h>

// Opaque struct performing the workload of the library
typedef struct OccurrenceSeries OccurrenceSeries;

// Specifies which direction to round to an occurrence
enum RecurrenceRoundingDirection {
    RECURRENCE_ROUND_UP,
    RECURRENCE_ROUND_DOWN,
};

// Convert the human-readable series description in <description> to an
// OccurrenceSeries
OccurrenceSeries* recurrence_series_new(char* description);

// Free internal memory used by an OccurrenceSeries
void recurrence_series_free(OccurrenceSeries** series);

// Canonicalize <occurrence> to the occurrence series <series>, rounding up or
// down to the nearest occurrence in the series based on <direction>.
time_t recurrence_canonicalize(time_t occurrence, OccurrenceSeries* series,
    enum RecurrenceRoundingDirection direction);

// Return the next occurrence in the series <series>, whether <occurrence> is
// a canonical occurrence in <series> or not.
time_t recurrence_next_occurrence(time_t occurrence, OccurrenceSeries* series);

#endif // RECURRENCE_H

///////////////////////////////////////////////////////////////////////////////
