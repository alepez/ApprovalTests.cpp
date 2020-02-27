#include "ApprovalException.h"

#include <sstream>

ApprovalTests::ApprovalException::ApprovalException(const std::string& msg)
    : message(msg)
{
}

const char* ApprovalTests::ApprovalException::what() const noexcept
{
    return message.c_str();
}

std::string
ApprovalTests::ApprovalMismatchException::format(const std::string& received,
                                                 const std::string& approved)
{
    std::stringstream s;
    s << "Failed Approval: \n"
      << "Received does not match approved \n"
      << "Received : \"" << received << "\" \n"
      << "Approved : \"" << approved << "\"";
    return s.str();
}

ApprovalTests::ApprovalMismatchException::ApprovalMismatchException(
    const std::string& received, const std::string& approved)
    : ApprovalException(format(received, approved))
{
}

std::string
ApprovalTests::ApprovalMissingException::format(const std::string& file)
{
    std::stringstream s;
    s << "Failed Approval: \n"
      << "Approval File Not Found \n"
      << "File: \"" << file << '"';
    return s.str();
}

ApprovalTests::ApprovalMissingException::ApprovalMissingException(
    const std::string&, const std::string& approved)
    : ApprovalException(format(approved))
{
}
