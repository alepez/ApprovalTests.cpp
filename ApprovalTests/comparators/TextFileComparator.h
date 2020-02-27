#ifndef APPROVALTESTS_CPP_TEXTFILECOMPARATOR_H
#define APPROVALTESTS_CPP_TEXTFILECOMPARATOR_H

#include "ApprovalTests/core/ApprovalComparator.h"

#include <fstream>

namespace ApprovalTests
{
    class TextFileComparator : public ApprovalComparator
    {
    public:
        static std::ifstream::int_type
        getNextRelevantCharacter(std::ifstream& astream);

        virtual bool
        contentsAreEquivalent(std::string receivedPath,
                              std::string approvedPath) const override;
    };
}
#endif //APPROVALTESTS_CPP_TEXTFILECOMPARATOR_H
