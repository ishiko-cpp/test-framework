/*
    Copyright (c) 2005-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#ifndef _ISHIKO_TESTFRAMEWORK_CORE_TESTRESULT_H_
#define _ISHIKO_TESTFRAMEWORK_CORE_TESTRESULT_H_

#include <cstddef>

namespace Ishiko
{
namespace TestFramework
{

class Test;

class TestResult
{
public:
    enum EOutcome
    {
        eUnknown,
        ePassed,
        ePassedButMemoryLeaks,
        eException,
        eFailed
    };

public:
    TestResult(const Test& test);
    virtual ~TestResult() throw();

    EOutcome outcome() const;
    bool passed() const;
    void setOutcome(EOutcome outcome);

    void getPassRate(size_t& unknown, size_t& passed, size_t& passedButMemoryLeaks, size_t& exception, size_t& failed,
        size_t& total) const;

private:
    const Test& m_test;
    EOutcome m_outcome;
};

}
}

#endif
