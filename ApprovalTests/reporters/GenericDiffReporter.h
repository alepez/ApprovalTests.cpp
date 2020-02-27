#ifndef APPROVALTESTS_CPP_GENERICDIFFREPORTER_H
#define APPROVALTESTS_CPP_GENERICDIFFREPORTER_H

#include "CommandReporter.h"
#include "ApprovalTests/launchers/SystemLauncher.h"
#include <string>

namespace ApprovalTests
{
    class GenericDiffReporter : public CommandReporter
    {
    public:
        SystemLauncher launcher;

    public:
        explicit GenericDiffReporter(const std::string& program);

        explicit GenericDiffReporter(const DiffInfo& info);
    };
}

#endif //APPROVALTESTS_CPP_GENERICDIFFREPORTER_H
