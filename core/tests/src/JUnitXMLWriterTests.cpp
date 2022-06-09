/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#include "JUnitXMLWriterTests.h"
#include <Ishiko/TestFramework/Core/JUnitXMLWriter.hpp>

using namespace Ishiko;

JUnitXMLWriterTests::JUnitXMLWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "JUnitXMLWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("create test 1", CreateTest1);
}

void JUnitXMLWriterTests::ConstructorTest1(Test& test)
{
    JUnitXMLWriter junitXMLWriter;

    ISHIKO_TEST_PASS();
}

void JUnitXMLWriterTests::CreateTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getTestOutputPath("JUnitXMLWriterTests_CreateTest1.xml");

    JUnitXMLWriter junitXMLWriter;

    Error error;
    junitXMLWriter.create(outputPath, error);

    ISHIKO_TEST_FAIL_IF(error);

    junitXMLWriter.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("JUnitXMLWriterTests_CreateTest1.xml", "JUnitXMLWriterTests_CreateTest1.xml");
    ISHIKO_TEST_PASS();
}
