// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "HeapAllocationErrorsTest.hpp"

using namespace Ishiko;

HeapAllocationErrorsTest::HeapAllocationErrorsTest(const TestNumber& number, const std::string& name,
    void (*runFct)(Test& test))
    : Test(TestNumber(), name), m_innerObserver(std::make_shared<InnerObserver>(*this))
{
    m_test = std::make_shared<Test>(TestNumber(), name, runFct);
    // We pass in a special observer to filter out the lifecycle events as m_test is an implementation detail that
    // shouldn't be visible to the outside.
    m_test->observers().add(m_innerObserver);
}

HeapAllocationErrorsTest::HeapAllocationErrorsTest(const TestNumber& number, const std::string& name,
    void (*runFct)(Test& test), const TestContext& context)
    : Test(TestNumber(), name, context), m_innerObserver(std::make_shared<InnerObserver>(*this))
{
    m_test = std::make_shared<Test>(TestNumber(), name, runFct, context);
    // We pass in a special observer to filter out the lifecycle events as m_test is an implementation detail that
    // shouldn't be visible to the outside.
    m_test->observers().add(m_innerObserver);
}

void HeapAllocationErrorsTest::addToJUnitXMLTestReport(JUnitXMLWriter& writer) const
{
    m_test->addToJUnitXMLTestReport(writer);
}

void HeapAllocationErrorsTest::doRun()
{
    m_test->run();

    setResult(m_test->result());
}

HeapAllocationErrorsTest::InnerObserver::InnerObserver(Test& test)
    : m_test(test)
{
}

void HeapAllocationErrorsTest::InnerObserver::onCheckFailed(const Test& source, const std::string& message,
    const char* file, int line)
{
    m_test.observers().notifyCheckFailed(source, message, file, line);
}

void HeapAllocationErrorsTest::InnerObserver::onExceptionThrown(const Test& source, std::exception_ptr exception)
{
    m_test.observers().notifyExceptionThrown(source, exception);
}
