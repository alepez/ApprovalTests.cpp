#include "DateUtils.h"

#include <sstream>
#include <iomanip>

namespace ApprovalTests
{
    std::tm
    DateUtils::createTm(int year, int month, int day, int hour, int minute, int second)
    {
        std::tm timeinfo = tm();
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        timeinfo.tm_hour = hour;
        timeinfo.tm_min = minute;
        timeinfo.tm_sec = second;
        return timeinfo;
    }

    std::chrono::system_clock::time_point
    DateUtils::createUtcDateTime(int year,
                                 int month,
                                 int day,
                                 int hour,
                                 int minute,
                                 int second) // these are UTC values
    {
        tm timeinfo = createTm(year, month, day, hour, minute, second);
        time_t tt = toUTC(timeinfo);
        return std::chrono::system_clock::from_time_t(tt);
    }

    std::string DateUtils::toString(const std::chrono::system_clock::time_point& dateTime)
    {
        return toString(dateTime, "%a %Y-%m-%d %H:%M:%S UTC");
    }

    std::string DateUtils::toString(const std::chrono::system_clock::time_point& dateTime,
                                    const std::string& format)
    {
        std::string result;
        time_t tt = std::chrono::system_clock::to_time_t(dateTime);

        tm tm_value = safeGmTime(tt);

        std::stringstream ss;
        ss << std::put_time(&tm_value, format.c_str());
        result = ss.str();
        return result;
    }

    time_t DateUtils::toUTC(std::tm& timeinfo)
    {
#ifdef _WIN32
        std::time_t tt = _mkgmtime(&timeinfo);
#else
        time_t tt = timegm(&timeinfo);
#endif
        return tt;
    }

    tm DateUtils::safeGmTime(time_t& tt)
    {
#ifdef _MSC_VER
        std::tm tm_value = {};
        gmtime_s(&tm_value, &tt);
#else
        tm tm_value = *gmtime(&tt); // GMT (UTC)
#endif
        return tm_value;
    }
}
