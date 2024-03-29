/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_FILECOMPARISONTESTCHECKTESTS_HPP_
#define _ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_FILECOMPARISONTESTCHECKTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class FileComparisonTestCheckTests : public Ishiko::TestSequence
{
public:
    FileComparisonTestCheckTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateFromContextTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
    static void RunTest2(Ishiko::Test& test);
    static void PersistentStorageTest1(Ishiko::Test& test);
    static void AddToJUnitXMLTestReportTest1(Ishiko::Test& test);
};

#endif
