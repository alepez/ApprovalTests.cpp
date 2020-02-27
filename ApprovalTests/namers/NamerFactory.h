#ifndef APPROVALTESTS_CPP_NAMERFACTORY_H
#define APPROVALTESTS_CPP_NAMERFACTORY_H

#include "SectionNameDisposer.h"

#include <string>

namespace ApprovalTests
{
    struct NamerFactory
    {
        static SectionNameDisposer
        appendToOutputFilename(const std::string& sectionName);
    };
}

#endif //APPROVALTESTS_CPP_NAMERFACTORY_H
