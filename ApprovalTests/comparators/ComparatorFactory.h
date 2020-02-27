#ifndef APPROVALTESTS_CPP_COMPARATORFACTORY_H
#define APPROVALTESTS_CPP_COMPARATORFACTORY_H

#include <memory>
#include "ApprovalTests/comparators/ComparatorDisposer.h"

namespace ApprovalTests
{

    class ComparatorFactory
    {
    private:
        static ComparatorContainer& comparators();

    public:
        static ComparatorDisposer
        registerComparator(const std::string& extensionWithDot,
                           std::shared_ptr<ApprovalComparator> comparator);

        static std::shared_ptr<ApprovalComparator>
        getComparatorForFile(const std::string& receivedPath);

        static std::shared_ptr<ApprovalComparator>
        getComparatorForFileExtensionWithDot(
            const std::string& fileExtensionWithDot);
    };
}

#endif //APPROVALTESTS_CPP_COMPARATORFACTORY_H
