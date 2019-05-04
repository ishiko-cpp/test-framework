/*
    Copyright (c) 2007-2019 Xavier Leclercq

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

#ifndef _ISHIKO_TEST_TESTFRAMEWORK_CORE_TESTTESTS_H_
#define _ISHIKO_TEST_TESTFRAMEWORK_CORE_TESTTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class TestTests : public Ishiko::Tests::TestSequence
{
public:
    TestTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void ConstructorTest2(Ishiko::Tests::Test& test);
    static void ConstructorTest3(Ishiko::Tests::Test& test);
    static void ConstructorTest4(Ishiko::Tests::Test& test);
    static void ConstructorTest5(Ishiko::Tests::Test& test);
    static void PassTest1(Ishiko::Tests::Test& test);
    static void FailTest1(Ishiko::Tests::Test& test);
    static void FailTest2(Ishiko::Tests::Test& test);
    static void FailIfTest1(Ishiko::Tests::Test& test);
    static void FailIfTest2(Ishiko::Tests::Test& test);
    static void FailIfTest3(Ishiko::Tests::Test& test);
    static void RunTest1(Ishiko::Tests::Test& test);
    static void RunTest2(Ishiko::Tests::Test& test);
    static void RunTest3(Ishiko::Tests::Test& test);
    static void RunTest4(Ishiko::Tests::Test& test);
    static void AbortTest1(Ishiko::Tests::Test& test);
};

#endif