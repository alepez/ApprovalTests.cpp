#ifndef APPROVALTESTS_CPP_SECTIONNAMEDISPOSER_H
#define APPROVALTESTS_CPP_SECTIONNAMEDISPOSER_H

#include "ApprovalTestNamer.h"
#include "ApprovalTests/utilities/Macros.h"

namespace ApprovalTests
{
    class APPROVAL_TESTS_NO_DISCARD SectionNameDisposer
    {
    public:
        SectionNameDisposer(TestName& currentTest,
                            const std::string& scope_name);

        ~SectionNameDisposer();

    private:
        TestName& currentTest;
    };
}

#endif //APPROVALTESTS_CPP_SECTIONNAMEDISPOSER_H
