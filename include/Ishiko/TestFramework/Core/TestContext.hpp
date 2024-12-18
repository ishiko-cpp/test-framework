// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTCONTEXT_HPP
#define GUARD_ISHIKO_CPP_TESTFRAMEWORK_CORE_TESTCONTEXT_HPP

#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/Text.hpp>
#include <map>

namespace Ishiko
{
    class TestContext : public InterpolatedString::Callbacks
    {
    public:
        enum class PathResolution
        {
            none,
            platform_specific
        };

        TestContext();
        TestContext(const TestContext* parent);
        ~TestContext() noexcept = default;
        static const TestContext& DefaultTestContext();

        void expand(boost::string_view variable, std::string& result, Error& error) const override;

        // This function is equivalent to calling getTestDataDirectory("(default)")
        // and exists to avoid the need to give a name to the test data
        // directory unnecessarily.
        boost::filesystem::path getDataDirectory() const;
        boost::filesystem::path getDataDirectory(const std::string& id) const;
        boost::filesystem::path getDataPath(const boost::filesystem::path& path) const;
        // Sets the default test data directory. The path argument
        // can contain environment variables by using the $(...) notation.
        // This is equivalent to calling setTestDataDirectory("(default)", path)
        // and exists to avoid the need to give a name to the test data
        // directory unnecessarily.
        void setDataDirectory(const boost::filesystem::path& path);
        // Adds or updates a path in the list of test data directories. The path argument
        // can contain environment variables by using the $(...) notation.
        void setDataDirectory(const std::string& id, const boost::filesystem::path& path);

        boost::filesystem::path getReferenceDirectory() const;
        boost::filesystem::path getReferenceDirectory(const std::string& id) const;
        boost::filesystem::path getReferencePath(const boost::filesystem::path& path,
            PathResolution path_resolution = PathResolution::none) const;
        // Sets the default reference data directory. The path argument
        // can contain environment variables by using the $(...) notation.
        void setReferenceDirectory(const boost::filesystem::path& path);
        void setReferenceDirectory(const std::string& id, const boost::filesystem::path& path);

        boost::filesystem::path getOutputDirectory() const;
        boost::filesystem::path getOutputDirectory(const std::string& id) const;
        boost::filesystem::path getOutputDirectory(const std::string& id, Error& error) const;
        boost::filesystem::path getOutputPath(const boost::filesystem::path& path) const;
        // Sets the default test output directory. The path argument
        // can contain environment variables by using the $(...) notation.
        void setOutputDirectory(const boost::filesystem::path& path);
        void setOutputDirectory(const std::string& id, const boost::filesystem::path& path);

        boost::filesystem::path getApplicationPath() const;
        void setApplicationPath(const boost::filesystem::path& path);

    private:
        const TestContext* m_parent;
        std::map<std::string, boost::filesystem::path> m_dataDirectories;
        std::map<std::string, boost::filesystem::path> m_referenceDirectories;
        std::map<std::string, boost::filesystem::path> m_outputDirectories;
        boost::optional<boost::filesystem::path> m_application_path;
    };
}

#endif
