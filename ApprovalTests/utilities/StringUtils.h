

#ifndef APPROVALTESTS_CPP_STRINGUTILS_H
#define APPROVALTESTS_CPP_STRINGUTILS_H

#include <string>
#include <sstream>

namespace ApprovalTests
{
    class StringUtils
    {
    public:
        static std::string replaceAll(std::string inText,
                                      const std::string& find,
                                      const std::string& replaceWith);

        static bool contains(const std::string& inText,
                             const std::string& find);

        static std::string toLower(std::string inText);

        static bool endsWith(std::string value, std::string ending);

        template <typename T> static std::string toString(const T& contents)
        {
            std::stringstream s;
            s << contents;
            return s.str();
        }
    };
}
#endif //APPROVALTESTS_CPP_STRINGUTILS_H
