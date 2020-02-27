#ifndef APPROVALTESTS_CPP_DEFAULTNAMERFACTORY_H
#define APPROVALTESTS_CPP_DEFAULTNAMERFACTORY_H

#include <memory>
#include <functional>

namespace ApprovalTests
{
    class ApprovalNamer;
    class ApprovalNamer;

    using NamerCreator = std::function<std::shared_ptr<ApprovalNamer>()>;

    //! Implementation detail of Approvals::useAsDefaultNamer()
    class DefaultNamerFactory
    {
    private:
        static NamerCreator& defaultNamer();

    public:
        static NamerCreator getDefaultNamer();

        static void setDefaultNamer(NamerCreator namer);
    };
}

#endif //APPROVALTESTS_CPP_DEFAULTNAMERFACTORY_H
