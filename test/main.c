///////////////////////////////////////////////////////////////////////////////
// NAME:            main.c
//
// AUTHOR:          Ethan D. Twardy <ethan.twardy@gmail.com>
//
// DESCRIPTION:     Entrypoint for testing
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <recurrence/recurrence.h>

int main(int argc, char** argv) {
    if (2 > argc) {
        printf("usage: %s <day_of_month>\n", argv[0]);
        exit(1);
    }

    char description[64] = {0};
    strcat(description, "monthly on the ");
    strcat(description, argv[1]);
    printf("description: %s\n", description);
    OccurrenceSeries* series = recurrence_series_new(description);
    recurrence_series_free(&series);
}

///////////////////////////////////////////////////////////////////////////////
