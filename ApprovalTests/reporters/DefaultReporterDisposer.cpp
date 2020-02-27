#include "DefaultReporterDisposer.h"

ApprovalTests::DefaultReporterDisposer::DefaultReporterDisposer(
    const std::shared_ptr<Reporter>& reporter)
{
    previous_result = DefaultReporterFactory::getDefaultReporter();
    DefaultReporterFactory::setDefaultReporter(reporter);
}

ApprovalTests::DefaultReporterDisposer::~DefaultReporterDisposer()
{
    DefaultReporterFactory::setDefaultReporter(previous_result);
}
