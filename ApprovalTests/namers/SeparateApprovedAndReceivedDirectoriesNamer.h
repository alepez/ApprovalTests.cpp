#ifndef APPROVALTESTS_CPP_SEPARATEAPPROVEDANDRECEIVEDDIRECTORIESNAMER_H
#define APPROVALTESTS_CPP_SEPARATEAPPROVEDANDRECEIVEDDIRECTORIESNAMER_H

#include "ApprovalTestNamer.h"
#include "DefaultNamerDisposer.h"

namespace ApprovalTests
{
    class SeparateApprovedAndReceivedDirectoriesNamer : public ApprovalTestNamer
    {
    public:
        virtual ~SeparateApprovedAndReceivedDirectoriesNamer() override =
            default;

        std::string getFullFileNameWithExtraDirectory(
            const std::string& approved,
            const std::string& extensionWithDot) const;

        virtual std::string
        getApprovedFile(std::string extensionWithDot) const override;

        virtual std::string
        getReceivedFile(std::string extensionWithDot) const override;

        static DefaultNamerDisposer useAsDefaultNamer();
    };
}

#endif // APPROVALTESTS_CPP_SEPARATEAPPROVEDANDRECEIVEDDIRECTORIESNAMER_H
