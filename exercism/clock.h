#ifndef CLOCK_H
#define CLOCK_H

#include <string>

namespace date_independent {

class clock {
private:
    int total_minutes;
    static int normalize_minutes(int minutes);
    explicit clock(int minutes);

public:
    static clock at(int hours, int minutes);

    clock plus(int minutes) const;
    clock minus(int minutes) const;

    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;

    explicit operator std::string() const;
};

} // namespace date_independent

#endif // CLOCK_H