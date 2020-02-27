#include "BlockingReporter.h"

namespace ApprovalTests
{
    BlockingReporter::BlockingReporter(std::shared_ptr<Blocker> blocker)
        : blocker(std::move(blocker))
    {
    }

    std::shared_ptr<BlockingReporter>
    BlockingReporter::onMachineNamed(const std::string& machineName)
    {
        auto machineBlocker = std::make_shared<MachineBlocker>(
            MachineBlocker::onMachineNamed(machineName));
        return std::make_shared<BlockingReporter>(machineBlocker);
    }

    std::shared_ptr<BlockingReporter>
    BlockingReporter::onMachinesNotNamed(const std::string& machineName)
    {
        auto machineBlocker = std::make_shared<MachineBlocker>(
            MachineBlocker::onMachinesNotNamed(machineName));
        return std::make_shared<BlockingReporter>(machineBlocker);
    }

    bool BlockingReporter::report(std::string, std::string) const
    {
        return blocker->isBlockingOnThisMachine();
    }
}
