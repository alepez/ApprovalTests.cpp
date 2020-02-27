#ifndef APPROVALTESTS_CPP_FILEAPPROVER_H
#define APPROVALTESTS_CPP_FILEAPPROVER_H

#include <memory>
#include "comparators/ComparatorDisposer.h"

namespace ApprovalTests
{
    class ApprovalComparator;
    class ApprovalNamer;
    class ApprovalWriter;
    class Reporter;

    class FileApprover
    {

    public:
        FileApprover() = default;

        ~FileApprover() = default;

        static ComparatorDisposer registerComparatorForExtension(
            const std::string& extensionWithDot,
            std::shared_ptr<ApprovalComparator> comparator);

        //! This overload is an implementation detail. To add a new comparator, use registerComparator().
        static void verify(const std::string& receivedPath,
                           const std::string& approvedPath,
                           const ApprovalComparator& comparator);

        static void verify(const std::string& receivedPath,
                           const std::string& approvedPath);

        static void verify(const ApprovalNamer& n,
                           const ApprovalWriter& s,
                           const Reporter& r);

        static void
        reportAfterTryingFrontLoadedReporter(const std::string& receivedPath,
                                             const std::string& approvedPath,
                                             const Reporter& r);
    };
}

#endif
