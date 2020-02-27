#ifndef APPROVALTESTS_CPP_DEFAULTREPORTERFACTORY_H
#define APPROVALTESTS_CPP_DEFAULTREPORTERFACTORY_H

#include <memory>

namespace ApprovalTests
{
    class Reporter;

    //! Implementation detail of Approvals::useAsDefaultReporter()
    class DefaultReporterFactory
    {
        // begin-snippet: static_variable_sample_header
    private:
        static std::shared_ptr<Reporter>& defaultReporter();

    public:
        static std::shared_ptr<Reporter> getDefaultReporter();

        static void
        setDefaultReporter(const std::shared_ptr<Reporter>& reporter);
        // end-snippet
    };
}

#endif //APPROVALTESTS_CPP_DEFAULTREPORTERFACTORY_H
