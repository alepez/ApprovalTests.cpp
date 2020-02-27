#include "ExistingFileNamer.h"

#include "DefaultNamerFactory.h"

namespace ApprovalTests
{
    ExistingFileNamer::ExistingFileNamer(std::string filePath)
        : filePath(std::move(filePath))
    {
    }

    std::string
    ExistingFileNamer::getApprovedFile(std::string extensionWithDot) const
    {
        return DefaultNamerFactory::getDefaultNamer()()->getApprovedFile(
            extensionWithDot);
    }

    std::string ExistingFileNamer::getReceivedFile(std::string) const
    {
        return filePath;
    }
}
