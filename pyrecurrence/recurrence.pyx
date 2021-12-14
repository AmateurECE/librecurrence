###############################################################################
# NAME:             recurrence.pyx
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Python wrapper for the library
#
# CREATED:          12/13/2021
#
# LAST EDITED:      12/14/2021
#
# Copyright 2021, Ethan D. Twardy
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
###

from libc.time cimport time_t
from datetime import datetime

cdef extern from "recurrence.h":
    # Opaque struct declaration
    struct OccurrenceSeries:
        pass

    OccurrenceSeries* recurrence_series_new(char* description);
    void recurrence_series_free(OccurrenceSeries** series);

    time_t recurrence_next_occurrence(
        time_t occurrence, OccurrenceSeries* series);

cdef class PyOccurrenceSeries:
    cdef OccurrenceSeries* series

    def __cinit__(self, description: str):
        series = recurrence_series_new(bytearray(description, 'ascii'))

    def next_occurrence(self, occurrence: datetime):
        cdef time_t next = recurrence_next_occurrence(occurrence.timestamp(),
            self.series)
        return datetime.fromtimestamp(next)

    def __dealloc__(self):
        recurrence_series_free(<OccurrenceSeries**>&(self.series))

###############################################################################
