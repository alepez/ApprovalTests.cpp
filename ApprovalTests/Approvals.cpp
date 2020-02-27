#include "ApprovalTests/Approvals.h"

namespace ApprovalTests
{
    std::shared_ptr<ApprovalNamer> Approvals::getDefaultNamer()
    {
        return DefaultNamerFactory::getDefaultNamer()();
    }

    void Approvals::verify(std::string contents, const Reporter& reporter)
    {
        verifyWithExtension(contents, ".txt", reporter);
    }

    void Approvals::verifyWithExtension(std::string contents,
                                        const std::string& fileExtensionWithDot,
                                        const Reporter& reporter)
    {
        StringWriter writer(contents, fileExtensionWithDot);
        FileApprover::verify(*getDefaultNamer(), writer, reporter);
    }

    void Approvals::verify(const ApprovalWriter& writer,
                           const Reporter& reporter)
    {
        FileApprover::verify(*getDefaultNamer(), writer, reporter);
    }

    void Approvals::verifyExceptionMessage(
        std::function<void(void)> functionThatThrows, const Reporter& reporter)
    {
        std::string message = "*** no exception thrown ***";
        try
        {
            functionThatThrows();
        }
        catch (const std::exception& e)
        {
            message = e.what();
        }
        verify(message, reporter);
    }

    void Approvals::verifyExistingFile(const std::string filePath,
                                       const Reporter& reporter)
    {
        ExistingFile writer(filePath);
        ExistingFileNamer namer(filePath);
        FileApprover::verify(namer, writer, reporter);
    }

    SubdirectoryDisposer
    Approvals::useApprovalsSubdirectory(std::string subdirectory)
    {
        return SubdirectoryDisposer(subdirectory);
    }

    DefaultReporterDisposer
    Approvals::useAsDefaultReporter(const std::shared_ptr<Reporter>& reporter)
    {
        return DefaultReporterDisposer(reporter);
    }

    FrontLoadedReporterDisposer Approvals::useAsFrontLoadedReporter(
        const std::shared_ptr<Reporter>& reporter)
    {
        return FrontLoadedReporterDisposer(reporter);
    }

    DefaultNamerDisposer Approvals::useAsDefaultNamer(NamerCreator namerCreator)
    {
        return DefaultNamerDisposer(namerCreator);
    }
}
