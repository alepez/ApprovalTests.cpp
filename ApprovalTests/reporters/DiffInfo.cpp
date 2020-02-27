#include "DiffInfo.h"

#include "ApprovalTests/utilities/FileUtils.h"
#include "ApprovalTests/utilities/StringUtils.h"
#include "ApprovalTests/utilities/SystemUtils.h"

namespace ApprovalTests
{

    std::string DiffInfo::receivedFileTemplate()
    {
        return "{Received}";
    }

    std::string DiffInfo::approvedFileTemplate()
    {
        return "{Approved}";
    }

    std::string DiffInfo::programFileTemplate()
    {
        return "{ProgramFiles}";
    }

    std::string DiffInfo::getDefaultArguments()
    {
        return receivedFileTemplate() + ' ' + approvedFileTemplate();
    }

    DiffInfo::DiffInfo(std::string program, Type type)
        : program(std::move(program))
        , arguments(getDefaultArguments())
        , type(type)
    {
    }

    DiffInfo::DiffInfo(std::string program, std::string arguments, Type type)
        : program(std::move(program))
        , arguments(std::move(arguments))
        , type(type)
    {
    }

    std::vector<std::string> DiffInfo::getProgramFileLocations()
    {
        std::vector<std::string> possibleWindowsPaths;
        const std::vector<const char*> envVars = {
            "ProgramFiles", "ProgramW6432", "ProgramFiles(x86)"};

        for (const auto& envVar : envVars)
        {
            std::string envVarValue = SystemUtils::safeGetEnv(envVar);
            if (!envVarValue.empty())
            {
                envVarValue += '\\';
                possibleWindowsPaths.push_back(envVarValue);
            }
        }
        return possibleWindowsPaths;
    }

    std::string DiffInfo::getProgramForOs() const
    {
        std::string result = program;
        if (result.rfind(programFileTemplate(), 0) == 0)
        {
            std::vector<std::string> possibleWindowsPaths =
                getProgramFileLocations();
            for (const auto& path : possibleWindowsPaths)
            {
                auto result1 = StringUtils::replaceAll(
                    result, programFileTemplate(), path);
                if (FileUtils::fileExists(result1))
                {
                    return result1;
                }
            }
        }
        return result;
    }
}