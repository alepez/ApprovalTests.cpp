#ifndef APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H
#define APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H

#include "ApprovalTests/core/Reporter.h"

namespace ApprovalTests
{
    class AutoApproveIfMissingReporter : public Reporter
    {
    public:
        bool report(std::string received, std::string approved) const override;
    };
}

#endif //APPROVALTESTS_CPP_AUTOAPPROVEIFMISSINGREPORTER_H
