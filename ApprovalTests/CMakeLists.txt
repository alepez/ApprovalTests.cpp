project(ApprovalTests CXX)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME}
        ApprovalTestsVersion.h
        Approvals.cpp
        Approvals.h
        CombinationApprovals.h
        comparators/ComparatorDisposer.cpp
        comparators/ComparatorDisposer.h
        comparators/ComparatorFactory.cpp
        comparators/ComparatorFactory.h
        comparators/TextFileComparator.cpp
        comparators/TextFileComparator.h
        core/ApprovalComparator.h
        core/ApprovalException.cpp
        core/ApprovalException.h
        core/ApprovalNamer.h
        core/ApprovalWriter.h
        core/FileApprover.cpp
        core/FileApprover.h
        core/Reporter.h
        integrations/CheckFileMacroIsAbsolute.h
        integrations/catch/Catch2Approvals.h
        integrations/doctest/DocTestApprovals.h
        integrations/google/GoogleConfiguration.cpp
        integrations/google/GoogleConfiguration.h
        integrations/google/GoogleCustomizationsFactory.cpp
        integrations/google/GoogleCustomizationsFactory.h
        integrations/google/GoogleTestApprovals.h
        integrations/ut/UTApprovals.h
        launchers/CommandLauncher.h
        launchers/SystemLauncher.cpp
        launchers/SystemLauncher.h
        namers/ApprovalTestNamer.cpp
        namers/ApprovalTestNamer.h
        namers/DefaultNamerDisposer.cpp
        namers/DefaultNamerDisposer.h
        namers/DefaultNamerFactory.cpp
        namers/DefaultNamerFactory.h
        namers/ExistingFileNamer.cpp
        namers/ExistingFileNamer.h
        namers/HelpMessages.cpp
        namers/HelpMessages.h
        namers/NamerFactory.cpp
        namers/NamerFactory.h
        namers/SectionNameDisposer.cpp
        namers/SectionNameDisposer.h
        namers/SeparateApprovedAndReceivedDirectoriesNamer.cpp
        namers/SeparateApprovedAndReceivedDirectoriesNamer.h
        namers/SubdirectoryDisposer.cpp
        namers/SubdirectoryDisposer.h
        reporters/AutoApproveIfMissingReporter.cpp
        reporters/AutoApproveIfMissingReporter.h
        reporters/AutoApproveReporter.cpp
        reporters/AutoApproveReporter.h
        reporters/BlockingReporter.cpp
        reporters/BlockingReporter.h
        reporters/CIBuildOnlyReporter.cpp
        reporters/CIBuildOnlyReporter.h
        reporters/CIBuildOnlyReporterUtils.cpp
        reporters/CIBuildOnlyReporterUtils.h
        reporters/ClipboardReporter.cpp
        reporters/ClipboardReporter.h
        reporters/CombinationReporter.cpp
        reporters/CombinationReporter.h
        reporters/CommandReporter.cpp
        reporters/CommandReporter.h
        reporters/ConvertForCygwin.cpp
        reporters/ConvertForCygwin.h
        reporters/CustomReporter.cpp
        reporters/CustomReporter.h
        reporters/DefaultFrontLoadedReporter.cpp
        reporters/DefaultFrontLoadedReporter.h
        reporters/DefaultReporter.cpp
        reporters/DefaultReporter.h
        reporters/DefaultReporterDisposer.cpp
        reporters/DefaultReporterDisposer.h
        reporters/DefaultReporterFactory.cpp
        reporters/DefaultReporterFactory.h
        reporters/DiffInfo.cpp
        reporters/DiffInfo.h
        reporters/DiffPrograms.h
        reporters/DiffReporter.cpp
        reporters/DiffReporter.h
        reporters/FirstWorkingReporter.cpp
        reporters/FirstWorkingReporter.h
        reporters/FrontLoadedReporterDisposer.cpp
        reporters/FrontLoadedReporterDisposer.h
        reporters/FrontLoadedReporterFactory.cpp
        reporters/FrontLoadedReporterFactory.h
        reporters/GenericDiffReporter.cpp
        reporters/GenericDiffReporter.h
        reporters/LinuxReporters.h
        reporters/MacReporters.h
        reporters/QuietReporter.cpp
        reporters/QuietReporter.h
        reporters/TextDiffReporter.cpp
        reporters/TextDiffReporter.h
        reporters/WindowsReporters.h
        utilities/Blocker.h
        utilities/CartesianProduct.h
        utilities/ExceptionCollector.cpp
        utilities/ExceptionCollector.h
        utilities/FileUtils.cpp
        utilities/FileUtils.h
        utilities/FileUtilsSystemSpecific.cpp
        utilities/FileUtilsSystemSpecific.h
        utilities/MachineBlocker.cpp
        utilities/MachineBlocker.h
        utilities/Macros.h
        utilities/StringUtils.cpp
        utilities/StringUtils.h
        utilities/SystemUtils.cpp
        utilities/SystemUtils.h
        utilities/WinMinGWUtils.h
        writers/ExistingFile.cpp
        writers/ExistingFile.h
        writers/StringWriter.cpp
        writers/StringWriter.h
        )
add_library(ApprovalTests::ApprovalTests ALIAS ApprovalTests)
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
target_compile_options(${PROJECT_NAME} PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/FC>)

if (("${CMAKE_GENERATOR}" MATCHES "Ninja") AND (${CMAKE_UNITY_BUILD}))
    # In case this is a Ninja Unity in-source build, disabling the
    # compile-time checking of __FILE__, to fix the compilation of our
    # Catch2 tests, and others which depend on __FILE__ - which then go on to pass,
    # even when built inside source trees.
    message(NOTICE "Ninja with Unity build detected: disabling unnecessary ApprovalTests compile-time check of __FILE__")
    target_compile_definitions(${PROJECT_NAME} PUBLIC APPROVALS_CATCH_DISABLE_FILE_MACRO_CHECK)
endif ()
