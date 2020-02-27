#ifndef APPROVALTESTS_CPP_MACHINEBLOCKER_H
#define APPROVALTESTS_CPP_MACHINEBLOCKER_H

#include "Blocker.h"

#include <string>

namespace ApprovalTests
{
    class MachineBlocker : public Blocker
    {
    private:
        std::string machineName;
        bool block;

        MachineBlocker() = delete;

    public:
        MachineBlocker(std::string machineName, bool block);

        static MachineBlocker onMachineNamed(const std::string& machineName);

        static MachineBlocker
        onMachinesNotNamed(const std::string& machineName);

        virtual bool isBlockingOnThisMachine() const override;
    };
}

#endif //APPROVALTESTS_CPP_MACHINEBLOCKER_H
