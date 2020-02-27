#ifndef APPROVALTESTS_CPP_FRONTLOADEDREPORTERDISPOSER_H
#define APPROVALTESTS_CPP_FRONTLOADEDREPORTERDISPOSER_H

#include "ApprovalTests/core/Reporter.h"
#include "ApprovalTests/utilities/Macros.h"

#include <memory>

namespace ApprovalTests
{
    //! Implementation detail of Approvals::useAsFrontLoadedReporter()
    class APPROVAL_TESTS_NO_DISCARD FrontLoadedReporterDisposer
    {
    private:
        std::shared_ptr<Reporter> previous_result;

    public:
        explicit FrontLoadedReporterDisposer(
            const std::shared_ptr<Reporter>& reporter);

        ~FrontLoadedReporterDisposer();
    };
}

#endif //APPROVALTESTS_CPP_FRONTLOADEDREPORTERDISPOSER_H
