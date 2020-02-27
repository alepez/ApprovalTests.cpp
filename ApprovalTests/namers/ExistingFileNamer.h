#ifndef APPROVALTESTS_CPP_EXISTINGFILENAMER_H
#define APPROVALTESTS_CPP_EXISTINGFILENAMER_H

#include "ApprovalTests/core/ApprovalNamer.h"

namespace ApprovalTests
{
    class ExistingFileNamer : public ApprovalNamer
    {
        std::string filePath;

    public:
        explicit ExistingFileNamer(std::string filePath);

        virtual std::string
        getApprovedFile(std::string extensionWithDot) const override;

        virtual std::string
            getReceivedFile(std::string /*extensionWithDot*/) const override;
    };
}

#endif //APPROVALTESTS_CPP_EXISTINGFILENAMER_H
