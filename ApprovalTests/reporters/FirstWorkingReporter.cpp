#include "FirstWorkingReporter.h"

namespace ApprovalTests
{
    FirstWorkingReporter::FirstWorkingReporter(
        const std::vector<Reporter*>& theReporters)
    {
        for (auto r : theReporters)
        {
            reporters.push_back(std::shared_ptr<Reporter>(r));
        }
    }

    FirstWorkingReporter::FirstWorkingReporter(
        const std::vector<std::shared_ptr<Reporter>>& reporters)
    {
        this->reporters = reporters;
    }

    bool FirstWorkingReporter::report(std::string received,
                                      std::string approved) const
    {
        for (auto& r : reporters)
        {
            if (r->report(received, approved))
            {
                return true;
            }
        }
        return false;
    }
}
