#pragma once

#include "SectionNameDisposer.h"

#include <string>

namespace ApprovalTests
{
    struct NamerFactory
    {
        static SectionNameDisposer appendToOutputFilename(const std::string& sectionName);
    };
}
