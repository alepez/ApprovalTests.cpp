#ifndef APPROVALTESTS_CPP_CUSTOMREPORTER_H
#define APPROVALTESTS_CPP_CUSTOMREPORTER_H

#include "GenericDiffReporter.h"
#include <memory>

namespace ApprovalTests
{
    struct DiffInfo;

    class CustomReporter
    {
    public:
        static std::shared_ptr<GenericDiffReporter>
        create(std::string path, Type type = Type::TEXT);

        static std::shared_ptr<GenericDiffReporter>
        create(std::string path, std::string arguments, Type type = Type::TEXT);

        static std::shared_ptr<GenericDiffReporter>
        createForegroundReporter(std::string path, Type type = Type::TEXT);

        static std::shared_ptr<GenericDiffReporter> createForegroundReporter(
            std::string path, std::string arguments, Type type = Type::TEXT);
    };
}

#endif //APPROVALTESTS_CPP_CUSTOMREPORTER_H
