#ifndef APPROVALTESTS_CPP_DIFFINFO_H
#define APPROVALTESTS_CPP_DIFFINFO_H

#include <string>
#include <vector>

namespace ApprovalTests
{
    enum class Type
    {
        TEXT,
        IMAGE,
        TEXT_AND_IMAGE
    };

    struct DiffInfo
    {
        static std::string receivedFileTemplate();

        static std::string approvedFileTemplate();

        static std::string programFileTemplate();

        static std::string getDefaultArguments();

        DiffInfo(std::string program, Type type);

        DiffInfo(std::string program, std::string arguments, Type type);

        std::string program;
        std::string arguments;
        Type type;

        static std::vector<std::string> getProgramFileLocations();

        std::string getProgramForOs() const;
    };
}

#endif //APPROVALTESTS_CPP_DIFFINFO_H
