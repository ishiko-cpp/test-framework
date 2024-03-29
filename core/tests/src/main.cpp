/*
    Copyright (c) 2007-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#include "DirectoryComparisonTestCheckTests.hpp"
#include "FileComparisonTestCheckTests.hpp"
#include "JUnitXMLWriterTests.hpp"
#include "TestContextTests.hpp"
#include "TestHarnessTests.hpp"
#include "TestNumberTests.hpp"
#include "TestTests.hpp"
#include "TestMacrosFormatterTests.h"
#include "TestMacrosTests.h"
#include "TestSequenceTests.h"
#include "ConsoleApplicationTestTests/ConsoleApplicationTestTests.h"
#include "HeapAllocationErrorsTestTests/HeapAllocationErrorsTestTests.h"
#include "TestSetupActionsTests/TestSetupActionsTests.h"
#include "TestTeardownActionsTests/TestTeardownActionsTests.h"
#include <Ishiko/Configuration.hpp>
#include <Ishiko/TestFramework/Core.hpp>
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification commandLineSpec;
        commandLineSpec.setDefaultValue("context.data", "../../data");
        commandLineSpec.setDefaultValue("context.output", "../../output");
        commandLineSpec.setDefaultValue("context.reference", "../../reference");

        Configuration configuration = commandLineSpec.createDefaultConfiguration();
        CommandLineParser::parse(commandLineSpec, argc, argv, configuration);

        TestHarness theTestHarness("IshikoTestFrameworkCore", configuration);

        TestSequence& theTests = theTestHarness.tests();
        theTests.append<TestContextTests>();
        theTests.append<TestNumberTests>();
        theTests.append<TestTests>();
        theTests.append<FileComparisonTestCheckTests>();
        theTests.append<DirectoryComparisonTestCheckTests>();
        theTests.append<TestMacrosFormatterTests>();
        theTests.append<TestMacrosTests>();
        theTests.append<TestSequenceTests>();
        theTests.append<ConsoleApplicationTestTests>();
        theTests.append<HeapAllocationErrorsTestTests>();
        theTests.append<TestSetupActionsTests>();
        theTests.append<TestTeardownActionsTests>();
        theTests.append<JUnitXMLWriterTests>();
        theTests.append<TestHarnessTests>();

        return theTestHarness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
