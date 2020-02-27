#ifndef APPROVALTESTS_CPP_HELPMESSAGES_H
#define APPROVALTESTS_CPP_HELPMESSAGES_H

#include <string>

// <SingleHpp unalterable>
namespace ApprovalTests
{
    class HelpMessages
    {
    public:
        static std::string
        getMisconfiguredBuildHelp(const std::string& fileName);

        static std::string getMisconfiguredMainHelp();

        static std::string topAndTailHelpMessage(const std::string& message);
    };
}
// </SingleHpp>

#endif //APPROVALTESTS_CPP_HELPMESSAGES_H
