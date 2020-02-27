#include "FileApprover.h"

#include "ApprovalException.h"
#include "ApprovalTests/core/ApprovalNamer.h"
#include "ApprovalTests/reporters/FrontLoadedReporterDisposer.h"
#include "ApprovalTests/comparators/ComparatorFactory.h"
#include "ApprovalTests/core/ApprovalWriter.h"
#include "ApprovalTests/utilities/FileUtils.h"

ApprovalTests::ComparatorDisposer
ApprovalTests::FileApprover::registerComparatorForExtension(
    const std::string& extensionWithDot,
    std::shared_ptr<ApprovalComparator> comparator)
{
    return ComparatorFactory::registerComparator(extensionWithDot, comparator);
}

void ApprovalTests::FileApprover::verify(
    const std::string& receivedPath,
    const std::string& approvedPath,
    const ApprovalTests::ApprovalComparator& comparator)
{
    if (!FileUtils::fileExists(approvedPath))
    {
        throw ApprovalMissingException(receivedPath, approvedPath);
    }

    if (!FileUtils::fileExists(receivedPath))
    {
        throw ApprovalMissingException(approvedPath, receivedPath);
    }

    if (!comparator.contentsAreEquivalent(receivedPath, approvedPath))
    {
        throw ApprovalMismatchException(receivedPath, approvedPath);
    }
}

void ApprovalTests::FileApprover::verify(const std::string& receivedPath,
                                         const std::string& approvedPath)
{
    verify(receivedPath,
           approvedPath,
           *ComparatorFactory::getComparatorForFile(receivedPath));
}

void ApprovalTests::FileApprover::verify(const ApprovalTests::ApprovalNamer& n,
                                         const ApprovalTests::ApprovalWriter& s,
                                         const ApprovalTests::Reporter& r)
{
    std::string approvedPath = n.getApprovedFile(s.getFileExtensionWithDot());
    std::string receivedPath = n.getReceivedFile(s.getFileExtensionWithDot());
    s.write(receivedPath);
    try
    {
        verify(receivedPath, approvedPath);
        s.cleanUpReceived(receivedPath);
    }
    catch (const ApprovalException&)
    {
        reportAfterTryingFrontLoadedReporter(receivedPath, approvedPath, r);
        throw;
    }
}

void ApprovalTests::FileApprover::reportAfterTryingFrontLoadedReporter(
    const std::string& receivedPath,
    const std::string& approvedPath,
    const ApprovalTests::Reporter& r)
{
    auto tryFirst = FrontLoadedReporterFactory::getFrontLoadedReporter();
    if (!tryFirst->report(receivedPath, approvedPath))
    {
        r.report(receivedPath, approvedPath);
    }
}
