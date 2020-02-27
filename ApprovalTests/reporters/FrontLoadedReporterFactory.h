#ifndef APPROVALTESTS_CPP_FRONTLOADEDREPORTERFACTORY_H
#define APPROVALTESTS_CPP_FRONTLOADEDREPORTERFACTORY_H

#include "ApprovalTests/core/Reporter.h"

#include <memory>

namespace ApprovalTests
{
    //! Implementation detail of Approvals::useAsFrontLoadedReporter()
    class FrontLoadedReporterFactory
    {
        static std::shared_ptr<Reporter>& frontLoadedReporter();

    public:
        static std::shared_ptr<Reporter> getFrontLoadedReporter();

        static void
        setFrontLoadedReporter(const std::shared_ptr<Reporter>& reporter);
    };
}

#endif //APPROVALTESTS_CPP_FRONTLOADEDREPORTERFACTORY_H
