#ifndef APPROVALTESTS_CPP_STRINGWRITER_H
#define APPROVALTESTS_CPP_STRINGWRITER_H

#include <string>
#include "ApprovalTests/core/ApprovalWriter.h"

namespace ApprovalTests
{
    class StringWriter : public ApprovalWriter
    {
    private:
        std::string s;
        std::string ext;

    public:
        explicit StringWriter(std::string contents,
                              std::string fileExtensionWithDot = ".txt");

        std::string getFileExtensionWithDot() const override;

        void write(std::string path) const override;

        void Write(std::ostream& out) const;

        virtual void cleanUpReceived(std::string receivedPath) const override;
    };
}
#endif
