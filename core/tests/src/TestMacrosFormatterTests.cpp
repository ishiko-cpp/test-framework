/*
    Copyright (c) 2021-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#include "TestMacrosFormatterTests.h"
#include <Ishiko/TestFramework/Core/TestMacrosFormatter.hpp>

using namespace Ishiko;

TestMacrosFormatterTests::TestMacrosFormatterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TestMacrosFormatter tests", context)
{
    append<HeapAllocationErrorsTest>("Format test 1", FormatTest1);
    append<HeapAllocationErrorsTest>("Format test 2", FormatTest2);
    append<HeapAllocationErrorsTest>("Format test 3", FormatTest3);
    append<HeapAllocationErrorsTest>("Format test 4", FormatTest4);
    append<HeapAllocationErrorsTest>("Format test 5", FormatTest5);
    append<HeapAllocationErrorsTest>("Format test 6", FormatTest6);
}

void TestMacrosFormatterTests::FormatTest1(Test& test)
{
    std::string value = "value";
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF", "value", value);

    ISHIKO_TEST_FAIL_IF_NEQ(output, "ISHIKO_TEST_FAIL_IF(value) failed with actual value (\"value\"s)");
    ISHIKO_TEST_PASS();
}


void TestMacrosFormatterTests::FormatTest2(Test& test)
{
    std::string value = "value";
    std::string reference = "reference";
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF_EQ", "value", "reference", value, reference);

    ISHIKO_TEST_FAIL_IF_NEQ(output,
        "ISHIKO_TEST_FAIL_IF_EQ(value, reference) failed with actual values (\"value\"s, \"reference\"s)");
    ISHIKO_TEST_PASS();
}

void TestMacrosFormatterTests::FormatTest3(Test& test)
{
    const char value[] = "value";
    const char reference[] = "reference";
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF_EQ", "value", "reference", value, reference);

    ISHIKO_TEST_FAIL_IF_NEQ(output,
        "ISHIKO_TEST_FAIL_IF_EQ(value, reference) failed with actual values (\"value\", \"reference\")");
    ISHIKO_TEST_PASS();
}

void TestMacrosFormatterTests::FormatTest4(Test& test)
{
    bool value = false;
    bool reference = true;
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF_EQ", "value", "reference", value, reference);

    ISHIKO_TEST_FAIL_IF_NEQ(output,
        "ISHIKO_TEST_FAIL_IF_EQ(value, reference) failed with actual values (false, true)");
    ISHIKO_TEST_PASS();
}

void TestMacrosFormatterTests::FormatTest5(Test& test)
{
    int value = 5;
    int reference = 7;
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF_EQ", "value", "reference", value, reference);

    ISHIKO_TEST_FAIL_IF_NEQ(output, "ISHIKO_TEST_FAIL_IF_EQ(value, reference) failed with actual values (5, 7)");
    ISHIKO_TEST_PASS();
}

enum FormatComparisonTest6Helper
{
    value1 = 1,
    value2 = 5
};

void TestMacrosFormatterTests::FormatTest6(Test& test)
{
    FormatComparisonTest6Helper value = FormatComparisonTest6Helper::value1;
    FormatComparisonTest6Helper reference = FormatComparisonTest6Helper::value2;
    std::string output = TestMacrosFormatter::Format("ISHIKO_TEST_FAIL_IF_EQ", "value", "reference", value, reference);

    ISHIKO_TEST_FAIL_IF_NEQ(output, "ISHIKO_TEST_FAIL_IF_EQ(value, reference) failed with actual values (1, 5)");
    ISHIKO_TEST_PASS();
}
