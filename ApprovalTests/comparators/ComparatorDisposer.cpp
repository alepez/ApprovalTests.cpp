#include "ComparatorDisposer.h"

ApprovalTests::ComparatorDisposer::ComparatorDisposer(
    ComparatorContainer& comparators,
    const std::string& extensionWithDot,
    std::shared_ptr<ApprovalTests::ApprovalComparator> previousComparator,
    std::shared_ptr<ApprovalTests::ApprovalComparator> newComparator)
    : comparators(comparators)
    , ext_(extensionWithDot)
    , previousComparator(std::move(previousComparator))
{
    comparators[extensionWithDot] = std::move(newComparator);
}

ApprovalTests::ComparatorDisposer::ComparatorDisposer(
    ApprovalTests::ComparatorDisposer&& other) noexcept
    : comparators(other.comparators)
    , ext_(std::move(other.ext_))
    , previousComparator(std::move(other.previousComparator))
{
    other.isActive = false;
}

ApprovalTests::ComparatorDisposer::~ComparatorDisposer()
{
    if (isActive)
    {
        comparators[ext_] = previousComparator;
    }
}
