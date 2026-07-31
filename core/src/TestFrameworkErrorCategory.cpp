/*
    Copyright (c) 2022-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#include "TestFrameworkErrorCategory.hpp"

using namespace Ishiko;

TestFrameworkErrorCategory::TestFrameworkErrorCategory() noexcept
    : ErrorCategory(ID(0x7df0f408105f46a0ULL, 0xa804b695cde3bf68ULL)) // 7df0f408-105f-46a0-a804-b695cde3bf68
{
}

const TestFrameworkErrorCategory& TestFrameworkErrorCategory::Get() noexcept
{
    static TestFrameworkErrorCategory theCategory;
    return theCategory;
}

const char* TestFrameworkErrorCategory::name() const noexcept
{
    return "Ishiko::TestFrameworkErrorCategory";
}

const char* TestFrameworkErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    default:
        return "unknown value";
    }
}

void Ishiko::Throw(TestFrameworkErrorCategory::Value value, const char* file, int line)
{
    throw Exception(static_cast<int>(value), TestFrameworkErrorCategory::Get(), file, line);
}

void Ishiko::Fail(TestFrameworkErrorCategory::Value value, Error& error) noexcept
{
    error.fail(TestFrameworkErrorCategory::Get(), static_cast<int>(value));
}
