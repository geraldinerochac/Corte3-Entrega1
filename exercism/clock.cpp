#include "clock.h"
#include <sstream>
#include <iomanip>

namespace date_independent {

int clock::normalize_minutes(int minutes) {
    const int minutes_in_day = 24 * 60;
    int normalized = minutes % minutes_in_day;
    if (normalized < 0) {
        normalized += minutes_in_day;
    }
    return normalized;
}

clock::clock(int minutes) : total_minutes(normalize_minutes(minutes)) {}

clock clock::at(int hours, int minutes) {
    return clock(hours * 60 + minutes);
}

clock clock::plus(int minutes) const {
    return clock(total_minutes + minutes);
}

clock clock::minus(int minutes) const {
    return clock(total_minutes - minutes);
}

bool clock::operator==(const clock& other) const {
    return total_minutes == other.total_minutes;
}

bool clock::operator!=(const clock& other) const {
    return !(*this == other);
}

clock::operator std::string() const {
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;
    
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours
        << ":"
        << std::setfill('0') << std::setw(2) << minutes;
    return oss.str();
}

} // namespace date_independent

