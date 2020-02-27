#ifndef APPROVALTESTS_CPP_EXISTINGFILE_H
#define APPROVALTESTS_CPP_EXISTINGFILE_H

#include <string>
#include "ApprovalTests/core/ApprovalWriter.h"

namespace ApprovalTests
{
    class ExistingFile : public ApprovalWriter
    {
        std::string filePath;

    public:
        explicit ExistingFile(std::string filePath);
        virtual std::string getFileExtensionWithDot() const override;
        virtual void write(std::string /*path*/) const override;
        virtual void
            cleanUpReceived(std::string /*receivedPath*/) const override;
    };
}

#endif
