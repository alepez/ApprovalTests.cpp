#include "AutoApproveReporter.h"
#include "ApprovalTests/utilities/FileUtilsSystemSpecific.h"

#include <iostream>

bool ApprovalTests::AutoApproveReporter::report(std::string received,
                                                std::string approved) const
{
    std::cout << "file " << approved
              << " automatically approved - next run should succeed\n";
    FileUtilsSystemSpecific::copyFile(received, approved);
    return true;
}