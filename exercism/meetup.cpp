#include "meetup.h"

namespace meetup {

scheduler::scheduler(int m, int y) : month(m), year(y) {}

boost::gregorian::date find_meetup(int year, int month, boost::gregorian::greg_weekday wd, int week_num) {
    using namespace boost::gregorian;
    
    if (week_num >= 1 && week_num <= 4) {
        date d(year, month, 1);
        while (d.day_of_week() != wd) {
            d += days(1);
        }
        d += weeks(week_num - 1);
        return d;
    } 
    else if (week_num == 5) {
        for (int day = 13; day <= 19; ++day) {
            date d(year, month, day);
            if (d.day_of_week() == wd) {
                return d;
            }
        }
    } 
    else if (week_num == 6) {
        date d(year, month, 1);
        d = d.end_of_month();
        while (d.day_of_week() != wd) {
            d -= days(1);
        }
        return d;
    }
    
    return date(year, month, 1);
}

boost::gregorian::date scheduler::monteenth() const { return find_meetup(year, month, boost::gregorian::Monday, 5); }
boost::gregorian::date scheduler::tuesteenth() const { return find_meetup(year, month, boost::gregorian::Tuesday, 5); }
boost::gregorian::date scheduler::wednesteenth() const { return find_meetup(year, month, boost::gregorian::Wednesday, 5); }
boost::gregorian::date scheduler::thursteenth() const { return find_meetup(year, month, boost::gregorian::Thursday, 5); }
boost::gregorian::date scheduler::friteenth() const { return find_meetup(year, month, boost::gregorian::Friday, 5); }
boost::gregorian::date scheduler::saturteenth() const { return find_meetup(year, month, boost::gregorian::Saturday, 5); }
boost::gregorian::date scheduler::sunteenth() const { return find_meetup(year, month, boost::gregorian::Sunday, 5); }

boost::gregorian::date scheduler::first_monday() const { return find_meetup(year, month, boost::gregorian::Monday, 1); }
boost::gregorian::date scheduler::first_tuesday() const { return find_meetup(year, month, boost::gregorian::Tuesday, 1); }
boost::gregorian::date scheduler::first_wednesday() const { return find_meetup(year, month, boost::gregorian::Wednesday, 1); }
boost::gregorian::date scheduler::first_thursday() const { return find_meetup(year, month, boost::gregorian::Thursday, 1); }
boost::gregorian::date scheduler::first_friday() const { return find_meetup(year, month, boost::gregorian::Friday, 1); }
boost::gregorian::date scheduler::first_saturday() const { return find_meetup(year, month, boost::gregorian::Saturday, 1); }
boost::gregorian::date scheduler::first_sunday() const { return find_meetup(year, month, boost::gregorian::Sunday, 1); }

boost::gregorian::date scheduler::second_monday() const { return find_meetup(year, month, boost::gregorian::Monday, 2); }
boost::gregorian::date scheduler::second_tuesday() const { return find_meetup(year, month, boost::gregorian::Tuesday, 2); }
boost::gregorian::date scheduler::second_wednesday() const { return find_meetup(year, month, boost::gregorian::Wednesday, 2); }
boost::gregorian::date scheduler::second_thursday() const { return find_meetup(year, month, boost::gregorian::Thursday, 2); }
boost::gregorian::date scheduler::second_friday() const { return find_meetup(year, month, boost::gregorian::Friday, 2); }
boost::gregorian::date scheduler::second_saturday() const { return find_meetup(year, month, boost::gregorian::Saturday, 2); }
boost::gregorian::date scheduler::second_sunday() const { return find_meetup(year, month, boost::gregorian::Sunday, 2); }

boost::gregorian::date scheduler::third_monday() const { return find_meetup(year, month, boost::gregorian::Monday, 3); }
boost::gregorian::date scheduler::third_tuesday() const { return find_meetup(year, month, boost::gregorian::Tuesday, 3); }
boost::gregorian::date scheduler::third_wednesday() const { return find_meetup(year, month, boost::gregorian::Wednesday, 3); }
boost::gregorian::date scheduler::third_thursday() const { return find_meetup(year, month, boost::gregorian::Thursday, 3); }
boost::gregorian::date scheduler::third_friday() const { return find_meetup(year, month, boost::gregorian::Friday, 3); }
boost::gregorian::date scheduler::third_saturday() const { return find_meetup(year, month, boost::gregorian::Saturday, 3); }
boost::gregorian::date scheduler::third_sunday() const { return find_meetup(year, month, boost::gregorian::Sunday, 3); }

boost::gregorian::date scheduler::fourth_monday() const { return find_meetup(year, month, boost::gregorian::Monday, 4); }
boost::gregorian::date scheduler::fourth_tuesday() const { return find_meetup(year, month, boost::gregorian::Tuesday, 4); }
boost::gregorian::date scheduler::fourth_wednesday() const { return find_meetup(year, month, boost::gregorian::Wednesday, 4); }
boost::gregorian::date scheduler::fourth_thursday() const { return find_meetup(year, month, boost::gregorian::Thursday, 4); }
boost::gregorian::date scheduler::fourth_friday() const { return find_meetup(year, month, boost::gregorian::Friday, 4); }
boost::gregorian::date scheduler::fourth_saturday() const { return find_meetup(year, month, boost::gregorian::Saturday, 4); }
boost::gregorian::date scheduler::fourth_sunday() const { return find_meetup(year, month, boost::gregorian::Sunday, 4); }

boost::gregorian::date scheduler::last_monday() const { return find_meetup(year, month, boost::gregorian::Monday, 6); }
boost::gregorian::date scheduler::last_tuesday() const { return find_meetup(year, month, boost::gregorian::Tuesday, 6); }
boost::gregorian::date scheduler::last_wednesday() const { return find_meetup(year, month, boost::gregorian::Wednesday, 6); }
boost::gregorian::date scheduler::last_thursday() const { return find_meetup(year, month, boost::gregorian::Thursday, 6); }
boost::gregorian::date scheduler::last_friday() const { return find_meetup(year, month, boost::gregorian::Friday, 6); }
boost::gregorian::date scheduler::last_saturday() const { return find_meetup(year, month, boost::gregorian::Saturday, 6); }
boost::gregorian::date scheduler::last_sunday() const { return find_meetup(year, month, boost::gregorian::Sunday, 6); }

} // namespace meetup
