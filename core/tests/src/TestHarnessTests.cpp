/*
    Copyright (c) 2007-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#include "TestHarnessTests.hpp"
#include "Ishiko/TestFramework/Core/TestHarness.hpp"
#include <boost/filesystem.hpp>
#include <Ishiko/Configuration.hpp>

using namespace Ishiko;

TestHarnessTests::TestHarnessTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TestHarness tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<HeapAllocationErrorsTest>("run test 1", RunTest1);
    append<HeapAllocationErrorsTest>("run test 2", RunTest2);
    append<HeapAllocationErrorsTest>("run test 3", RunTest3);
    append<HeapAllocationErrorsTest>("run test 4", RunTest4);
    append<HeapAllocationErrorsTest>("JUnit XML test report test 1", JUnitXMLReportTest1);
    append<HeapAllocationErrorsTest>("JUnit XML test report test 2", JUnitXMLReportTest2);
    append<HeapAllocationErrorsTest>("JUnit XML test report test 3", JUnitXMLReportTest3);
    append<HeapAllocationErrorsTest>("JUnit XML test report test 4", JUnitXMLReportTest4);
}

void TestHarnessTests::ConstructorTest1(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_ConstructorTest1");

    ISHIKO_TEST_PASS();
}

void TestHarnessTests::ConstructorTest2(Test& test)
{
    // This is not really a persistent storage path, we only need an arbitrary path for testing 
    boost::filesystem::path outputPath = test.context().getOutputPath("TestHarnessTests_ConstructorTest2.xml");

    Configuration configuration = TestHarness::CommandLineSpecification().createDefaultConfiguration();
    configuration.set("persistent-storage", outputPath.string());
    TestHarness theTestHarness("TestHarnessTests_ConstructorTest2", configuration);

    ISHIKO_TEST_FAIL_IF_NEQ(theTestHarness.context().getOutputDirectory("persistent-storage"), outputPath);
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::RunTest1(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest1");
    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::testFailure);
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::RunTest2(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest2");

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::passed);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::ok);
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::RunTest3(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest3");

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::skipped);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::ok);
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::RunTest4(Test& test)
{
    TestHarness theTestHarness("TestHarnessTests_RunTest2");

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::passed);
    theTestHarness.tests().append(test1);
    std::shared_ptr<Test> test2 = std::make_shared<Test>(TestNumber(2), "Test", TestResult::failed);
    theTestHarness.tests().append(test2);

    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::testFailure);
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::JUnitXMLReportTest1(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath("TestHarnessTests_JUnitXMLReportTest1.xml");

    Configuration configuration = TestHarness::CommandLineSpecification().createDefaultConfiguration();
    configuration.set("junit-xml-test-report", outputPath.string());
    TestHarness theTestHarness("TestHarnessTests_JUnitXMLReportTest1", configuration);
 
    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::testFailure);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("TestHarnessTests_JUnitXMLReportTest1.xml");
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::JUnitXMLReportTest2(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath("TestHarnessTests_JUnitXMLReportTest2.xml");

    Configuration configuration = TestHarness::CommandLineSpecification().createDefaultConfiguration();
    configuration.set("junit-xml-test-report", outputPath.string());
    TestHarness theTestHarness("TestHarnessTests_JUnitXMLReportTest2", configuration);

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::passed);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();
    
    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::ok);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("TestHarnessTests_JUnitXMLReportTest2.xml");
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::JUnitXMLReportTest3(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath("TestHarnessTests_JUnitXMLReportTest3.xml");

    Configuration configuration = TestHarness::CommandLineSpecification().createDefaultConfiguration();
    configuration.set("junit-xml-test-report", outputPath.string());
    TestHarness theTestHarness("TestHarnessTests_JUnitXMLReportTest3", configuration);

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::skipped);
    theTestHarness.tests().append(test1);

    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::ok);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("TestHarnessTests_JUnitXMLReportTest3.xml");
    ISHIKO_TEST_PASS();
}

void TestHarnessTests::JUnitXMLReportTest4(Test& test)
{
    boost::filesystem::path outputPath = test.context().getOutputPath("TestHarnessTests_JUnitXMLReportTest4.xml");

    Configuration configuration = TestHarness::CommandLineSpecification().createDefaultConfiguration();
    configuration.set("junit-xml-test-report", outputPath.string());
    TestHarness theTestHarness("TestHarnessTests_JUnitXMLReportTest4", configuration);

    std::shared_ptr<Test> test1 = std::make_shared<Test>(TestNumber(1), "Test", TestResult::passed);
    theTestHarness.tests().append(test1);
    std::shared_ptr<Test> test2 = std::make_shared<Test>(TestNumber(2), "Test", TestResult::failed);
    theTestHarness.tests().append(test2);

    int returnCode = theTestHarness.run();

    ISHIKO_TEST_FAIL_IF_NEQ(returnCode, TestApplicationReturnCode::testFailure);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("TestHarnessTests_JUnitXMLReportTest4.xml");
    ISHIKO_TEST_PASS();
}
