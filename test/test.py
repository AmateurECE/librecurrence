###############################################################################
# NAME:             test.py
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Test the Python3 Wrappers for librecurrence
#
# CREATED:          12/14/2021
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

from datetime import datetime
from importlib import util
import sys

def main(pyrecurrence):
    series = pyrecurrence.PyOccurrenceSeries("monthly on the 3rd")
    now = datetime.now()
    print(now.strftime("%A, %d %B %Y %I:%M %p"))
    next = series.next_occurrence(now)
    print(next)

if __name__ == '__main__':
    # Load the module
    pyrecurrence_spec = util.spec_from_file_location("pyrecurrence",
                                                     sys.argv[1])
    pyrecurrence = util.module_from_spec(pyrecurrence_spec)
    pyrecurrence_spec.loader.exec_module(pyrecurrence)
    main(pyrecurrence)

###############################################################################
