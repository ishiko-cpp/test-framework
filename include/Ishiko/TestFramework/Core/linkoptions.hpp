// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_LINKOPTIONS_HPP
#define GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_LINKOPTIONS_HPP

#include <Ishiko/BasePlatform/linkoptions.hpp>
#include <Ishiko/FileSystem/linkoptions.hpp>
#include <Ishiko/Process/linkoptions.hpp>

#ifdef _DEBUG
#pragma comment(lib, "IshikoTestFrameworkCore-d.lib")
#else
#pragma comment(lib, "IshikoTestFrameworkCore.lib")
#endif

#endif
