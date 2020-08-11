#include "ApprovalTests/reporters/DiffReporter.h"

#include "WindowsReporters.h"
#include "MacReporters.h"
#include "LinuxReporters.h"

namespace ApprovalTests
{
    enum class Os
    {
        Unknown,
        Linux,
        Mac,
        Windows,
    };

    /// Detect operating system at compile time
    constexpr Os detectOs()
    {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        return Os::Windows;
#elif __APPLE__
        return Os::Mac;
#elif __linux__
        return Os::Linux;
#else
        return Os::Unknown;
#endif
    }

    std::vector<Reporter*> linuxReporters()
    {
        return std::vector<Reporter*>{{
            new Linux::LinuxDiffReporter(),
            new Mac::MacDiffReporter(),
            new Windows::WindowsDiffReporter(),
        }};
    }

    std::vector<Reporter*> windowsReporters()
    {
        return std::vector<Reporter*>{{
            new Windows::WindowsDiffReporter(),
            new Linux::LinuxDiffReporter(),
            new Mac::MacDiffReporter(),
        }};
    }

    std::vector<Reporter*> macReporters()
    {
        return std::vector<Reporter*>{{
            new Mac::MacDiffReporter(),
            new Linux::LinuxDiffReporter(),
            new Windows::WindowsDiffReporter(),
        }};
    }

    /// Get best reporters for the given operating system
    std::vector<Reporter*> osReporters(Os os)
    {
        switch (os)
        {
        case Os::Linux:
            return linuxReporters();
        case Os::Windows:
            return windowsReporters();
        default:
            break;
        }

        return macReporters();
    }

    DiffReporter::DiffReporter() : FirstWorkingReporter(osReporters(detectOs()))
    {
    }
}
