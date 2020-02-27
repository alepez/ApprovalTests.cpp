#include "AutoApproveIfMissingReporter.h"
#include "AutoApproveReporter.h"
#include "ApprovalTests/utilities/FileUtils.h"

bool ApprovalTests::AutoApproveIfMissingReporter::report(
    std::string received, std::string approved) const
{
    if (FileUtils::fileExists(approved))
    {
        return false;
    }

    return AutoApproveReporter().report(received, approved);
}
