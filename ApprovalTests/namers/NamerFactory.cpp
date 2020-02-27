#include "NamerFactory.h"

#include "ApprovalTestNamer.h"

namespace ApprovalTests
{
    SectionNameDisposer
    NamerFactory::appendToOutputFilename(const std::string& sectionName)
    {
        return SectionNameDisposer(ApprovalTestNamer::currentTest(),
                                   sectionName);
    }
}
