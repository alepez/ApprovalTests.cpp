#include "CIBuildOnlyReporterUtils.h"

#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/reporters/CIBuildOnlyReporter.h"

namespace ApprovalTests
{
    FrontLoadedReporterDisposer
    CIBuildOnlyReporterUtils::useAsFrontLoadedReporter(
        const std::shared_ptr<Reporter>& reporter)
    {
        return Approvals::useAsFrontLoadedReporter(
            std::make_shared<CIBuildOnlyReporter>(reporter));
    }
}
