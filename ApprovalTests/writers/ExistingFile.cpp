#include "ExistingFile.h"

#include "ApprovalTests/utilities/FileUtils.h"

namespace ApprovalTests
{
    ExistingFile::ExistingFile(std::string filePath)
        : filePath(std::move(filePath))
    {
    }

    std::string ExistingFile::getFileExtensionWithDot() const
    {
        return FileUtils::getExtensionWithDot(filePath);
    }

    void ExistingFile::write(std::string) const
    {
        // do nothing
    }

    void ExistingFile::cleanUpReceived(std::string) const
    {
        // do nothing
    }
}
