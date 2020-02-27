#ifndef APPROVALTESTS_CPP_CIBUILDONLYREPORTERUTILS_H
#define APPROVALTESTS_CPP_CIBUILDONLYREPORTERUTILS_H

#include "ApprovalTests/reporters/FrontLoadedReporterDisposer.h"

#include <memory>

namespace ApprovalTests
{
    namespace CIBuildOnlyReporterUtils
    {
        FrontLoadedReporterDisposer
        useAsFrontLoadedReporter(const std::shared_ptr<Reporter>& reporter);
    }
} // namespace ApprovalTests

#endif //APPROVALTESTS_CPP_CIBUILDONLYREPORTERUTILS_H
