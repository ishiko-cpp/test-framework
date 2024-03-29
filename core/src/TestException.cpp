/*
    Copyright (c) 2015-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/test-framework/blob/main/LICENSE.txt
*/

#include "TestException.hpp"

namespace Ishiko
{

TestException::TestException(const std::string& message)
    : std::runtime_error(message)
{
}

}
