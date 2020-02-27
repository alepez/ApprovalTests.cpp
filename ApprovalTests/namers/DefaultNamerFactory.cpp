#include "DefaultNamerFactory.h"

#include "ApprovalTestNamer.h"

ApprovalTests::NamerCreator& ApprovalTests::DefaultNamerFactory::defaultNamer()
{
    static NamerCreator namer = []() {
        return std::make_shared<ApprovalTestNamer>();
    };
    return namer;
}

ApprovalTests::NamerCreator
ApprovalTests::DefaultNamerFactory::getDefaultNamer()
{
    return defaultNamer();
}

void ApprovalTests::DefaultNamerFactory::setDefaultNamer(
    ApprovalTests::NamerCreator namer)
{
    defaultNamer() = std::move(namer);
}
