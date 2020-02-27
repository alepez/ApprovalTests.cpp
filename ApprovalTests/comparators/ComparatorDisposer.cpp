#include "ComparatorDisposer.h"

namespace ApprovalTests
{
    ComparatorDisposer::ComparatorDisposer(
        ComparatorContainer& comparators,
        const std::string& extensionWithDot,
        std::shared_ptr<ApprovalComparator> previousComparator,
        std::shared_ptr<ApprovalComparator> newComparator)
        : comparators(comparators)
        , ext_(extensionWithDot)
        , previousComparator(std::move(previousComparator))
    {
        comparators[extensionWithDot] = std::move(newComparator);
    }

    ComparatorDisposer::ComparatorDisposer(ComparatorDisposer&& other) noexcept
        : comparators(other.comparators)
        , ext_(std::move(other.ext_))
        , previousComparator(std::move(other.previousComparator))
    {
        other.isActive = false;
    }

    ComparatorDisposer::~ComparatorDisposer()
    {
        if (isActive)
        {
            comparators[ext_] = previousComparator;
        }
    }
}