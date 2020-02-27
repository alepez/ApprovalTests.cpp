project(ApprovalTests CXX)
set(CMAKE_CXX_STANDARD 11)
add_library(${PROJECT_NAME}
        Approvals.cpp
        comparators/ComparatorDisposer.cpp
        comparators/ComparatorFactory.cpp
        comparators/TextFileComparator.cpp
        core/ApprovalException.cpp
        core/FileApprover.cpp
        launchers/SystemLauncher.cpp
        namers/ApprovalTestNamer.cpp
        namers/DefaultNamerDisposer.cpp
        namers/DefaultNamerFactory.cpp
        namers/ExistingFileNamer.cpp
        namers/NamerFactory.cpp
        namers/SeparateApprovedAndReceivedDirectoriesNamer.cpp
        namers/SectionNameDisposer.cpp
        namers/HelpMessages.cpp
        namers/SubdirectoryDisposer.cpp
        reporters/AutoApproveIfMissingReporter.cpp
        reporters/AutoApproveReporter.cpp
        reporters/BlockingReporter.cpp
        reporters/CIBuildOnlyReporter.cpp
        reporters/CIBuildOnlyReporterUtils.cpp
        reporters/ClipboardReporter.cpp
        reporters/CombinationReporter.cpp
        reporters/CommandReporter.cpp
        reporters/ConvertForCygwin.cpp
        reporters/CustomReporter.cpp
        reporters/DefaultReporter.cpp
        reporters/DefaultReporterDisposer.cpp
        reporters/DefaultReporterFactory.cpp
        reporters/DiffInfo.cpp
        reporters/TextDiffReporter.cpp
        utilities/ExceptionCollector.cpp
        utilities/FileUtilsSystemSpecific.cpp
        utilities/FileUtils.cpp
        utilities/MachineBlocker.cpp
        utilities/StringUtils.cpp
        utilities/SystemUtils.cpp
        writers/ExistingFile.cpp
        writers/StringWriter.cpp
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
