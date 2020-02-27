#ifndef APPROVALTESTS_CPP_EXCEPTIONCOLLECTOR_H
#define APPROVALTESTS_CPP_EXCEPTIONCOLLECTOR_H

#include <string>
#include <vector>
#include <functional>

namespace ApprovalTests
{
    class ExceptionCollector
    {
        std::vector<std::string> exceptionMessages;

    public:
        void gather(std::function<void(void)> functionThatThrows);
        ~ExceptionCollector();

        void release();
    };
}

#endif //APPROVALTESTS_CPP_EXCEPTIONCOLLECTOR_H
