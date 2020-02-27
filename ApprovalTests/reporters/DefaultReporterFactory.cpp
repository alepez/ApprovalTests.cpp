#include "DefaultReporterFactory.h"

#include "ApprovalTests/core/Reporter.h"
#include "DiffReporter.h"

// begin-snippet: static_variable_sample_impl
std::shared_ptr<ApprovalTests::Reporter>&
ApprovalTests::DefaultReporterFactory::defaultReporter()
{
    static std::shared_ptr<Reporter> reporter =
        std::make_shared<DiffReporter>();
    return reporter;
}

std::shared_ptr<ApprovalTests::Reporter>
ApprovalTests::DefaultReporterFactory::getDefaultReporter()
{
    return defaultReporter();
}

void ApprovalTests::DefaultReporterFactory::setDefaultReporter(
    const std::shared_ptr<Reporter>& reporter)
{
    defaultReporter() = reporter;
}
// end-snippet
