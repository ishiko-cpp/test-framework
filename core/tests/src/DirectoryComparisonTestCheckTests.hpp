/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_DIRECTORYCOMPARISONTESTCHECKTESTS_HPP_
#define _ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_DIRECTORYCOMPARISONTESTCHECKTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class DirectoryComparisonTestCheckTests : public Ishiko::TestSequence
{
public:
    DirectoryComparisonTestCheckTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
    static void RunTest2(Ishiko::Test& test);
    static void RunTest3(Ishiko::Test& test);
    static void RunTest4(Ishiko::Test& test);
    static void RunTest5(Ishiko::Test& test);
    static void RunTest6(Ishiko::Test& test);
    static void RunTest7(Ishiko::Test& test);
    static void RunTest8(Ishiko::Test& test);
};

#endif
