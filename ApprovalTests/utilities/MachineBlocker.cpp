#include "MachineBlocker.h"

#include "SystemUtils.h"

namespace ApprovalTests
{
    MachineBlocker::MachineBlocker(std::string machineName, bool block)
        : machineName(std::move(machineName)), block(block)
    {
    }

    MachineBlocker
    MachineBlocker::onMachineNamed(const std::string& machineName)
    {
        return MachineBlocker(machineName, true);
    }

    MachineBlocker
    MachineBlocker::onMachinesNotNamed(const std::string& machineName)
    {
        return MachineBlocker(machineName, false);
    }

    bool MachineBlocker::isBlockingOnThisMachine() const
    {
        const auto isMachine = (SystemUtils::getMachineName() == machineName);
        return isMachine == block;
    }
}
