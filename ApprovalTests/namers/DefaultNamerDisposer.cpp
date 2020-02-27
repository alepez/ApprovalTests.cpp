#include "DefaultNamerDisposer.h"

ApprovalTests::DefaultNamerDisposer::DefaultNamerDisposer(
    ApprovalTests::NamerCreator namerCreator)
{
    previous_result = DefaultNamerFactory::getDefaultNamer();
    DefaultNamerFactory::setDefaultNamer(std::move(namerCreator));
}

ApprovalTests::DefaultNamerDisposer::~DefaultNamerDisposer()
{
    DefaultNamerFactory::setDefaultNamer(previous_result);
}
