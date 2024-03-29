/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TESTFRAMEWORK_CORE_JUNITXMLWRITER_HPP_
#define _ISHIKO_CPP_TESTFRAMEWORK_CORE_JUNITXMLWRITER_HPP_

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/XML.hpp>
#include <string>

namespace Ishiko
{

class JUnitXMLWriter
{
public:
    JUnitXMLWriter();
    void create(const boost::filesystem::path& path, Error& error);
    void close();

    void writeTestSuitesStart();
    void writeTestSuitesEnd();
    void writeTestSuiteStart(size_t tests);
    void writeTestSuiteEnd();
    void writeTestCaseStart(const std::string& classname, const std::string& name);
    void writeTestCaseEnd();
    void writeFailureStart();
    void writeFailureEnd();
    void writeSkippedStart();
    void writeSkippedEnd();
    void writeText(const std::string& text);

private:
    XMLWriter m_xmlWriter;
    bool m_atLeastOneTestSuite;
    bool m_atLeastOneTestCase;
    bool m_testCaseHasChild;
};

}

#endif
