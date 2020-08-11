#pragma once

#include "GenericDiffReporter.h"
#include "FirstWorkingReporter.h"

namespace ApprovalTests
{
    namespace Linux
    {
        class SublimeMergeSnapReporter : public GenericDiffReporter
        {
        public:
            SublimeMergeSnapReporter();
        };

        class SublimeMergeFlatpakReporter : public GenericDiffReporter
        {
        public:
            SublimeMergeFlatpakReporter();
        };

        class SublimeMergeRepositoryPackageReporter : public GenericDiffReporter
        {
        public:
            SublimeMergeRepositoryPackageReporter();
        };

        class SublimeMergeDirectDownloadReporter : public GenericDiffReporter
        {
        public:
            SublimeMergeDirectDownloadReporter();
        };

        class SublimeMergeReporter : public FirstWorkingReporter
        {
        public:
            SublimeMergeReporter();
        };

        class KDiff3Reporter : public GenericDiffReporter
        {
        public:
            KDiff3Reporter();
        };

        class MeldReporter : public GenericDiffReporter
        {
        public:
            MeldReporter();
        };

        class BeyondCompareReporter : public GenericDiffReporter
        {
        public:
            BeyondCompareReporter();
        };

        // See https://github.com/approvals/ApprovalTests.cpp/issues/138 for limitations
        class CLionDiffReporter : public GenericDiffReporter
        {
        public:
            CLionDiffReporter();
        };

        class LinuxDiffReporter : public FirstWorkingReporter
        {
        public:
            LinuxDiffReporter();
        };
    }
}
