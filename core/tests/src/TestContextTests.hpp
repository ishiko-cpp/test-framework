/*
    Copyright (c) 2007-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#ifndef GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_TESTCONTEXTTESTS_HPP
#define GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTS_TESTCONTEXTTESTS_HPP

#include <Ishiko/TestFramework/Core.hpp>

class TestContextTests : public Ishiko::TestSequence
{
public:
    TestContextTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
    static void ConstructorTest3(Ishiko::Test& test);
    static void GetTestDataDirectoryTest1(Ishiko::Test& test);
    static void GetTestDataDirectoryTest2(Ishiko::Test& test);
    static void GetTestDataDirectoryTest3(Ishiko::Test& test);
    static void GetTestDataDirectoryTest4(Ishiko::Test& test);
    static void GetTestDataDirectoryTest5(Ishiko::Test& test);
    static void GetTestDataPathTest1(Ishiko::Test& test);
    static void SetTestDataDirectoryTest1(Ishiko::Test& test);
    static void GetReferenceDataDirectoryTest1(Ishiko::Test& test);
    static void GetReferenceDataDirectoryTest2(Ishiko::Test& test);
    static void GetReferenceDataPathTest1(Ishiko::Test& test);
    static void GetReferenceDataPathTest2(Ishiko::Test& test);
    static void GetReferenceDataPathTest3(Ishiko::Test& test);
    static void GetReferenceDataPathTest4(Ishiko::Test& test);
    static void GetReferenceDataPathTest5(Ishiko::Test& test);
    static void SetReferenceDataDirectoryTest1(Ishiko::Test& test);
    static void GetTestOutputDirectoryTest1(Ishiko::Test& test);
    static void GetTestOutputDirectoryTest2(Ishiko::Test& test);
    static void GetTestOutputPathTest1(Ishiko::Test& test);
    static void SetTestOutputDirectoryTest1(Ishiko::Test& test);
};

#endif
