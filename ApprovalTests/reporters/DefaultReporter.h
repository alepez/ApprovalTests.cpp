#ifndef APPROVALTESTS_CPP_DEFAULTREPORTER_H
#define APPROVALTESTS_CPP_DEFAULTREPORTER_H

#include "ApprovalTests/core/Reporter.h"

#include <string>

namespace ApprovalTests
{
    class DefaultReporter : public Reporter
    {
    public:
        virtual bool report(std::string received,
                            std::string approved) const override;
    };
}

#endif //APPROVALTESTS_CPP_DEFAULTREPORTER_H
