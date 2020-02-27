#ifndef APPROVALTESTS_CPP_BLOCKINGREPORTER_H
#define APPROVALTESTS_CPP_BLOCKINGREPORTER_H

#include "ApprovalTests/core/Reporter.h"
#include "../utilities/MachineBlocker.h"

#include <memory>

namespace ApprovalTests
{
    class BlockingReporter : public Reporter
    {
    private:
        std::shared_ptr<Blocker> blocker;

        BlockingReporter() = delete;

    public:
        explicit BlockingReporter(std::shared_ptr<Blocker> blocker);

        static std::shared_ptr<BlockingReporter>
        onMachineNamed(const std::string& machineName);

        static std::shared_ptr<BlockingReporter>
        onMachinesNotNamed(const std::string& machineName);

        virtual bool report(std::string /*received*/,
                            std::string /*approved*/) const override;
    };
}

#endif //APPROVALTESTS_CPP_BLOCKINGREPORTER_H
