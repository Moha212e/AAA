#include "Timing.h"
#include "TimingException.h"
using namespace std;

namespace planning
{
    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    Time Timing::getDuration() const
    {
        return duration;
    }

    string Timing::getDay() const
    {
        return day;
    }

    Time Timing::getStart() const
    {
        return start;
    }

    void Timing::setStart(const Time &e)
    {
        start = e;
    }

    void Timing::setDuration(const Time &e)
    {
    
        duration = e;
    }

    void Timing::setDay(const string &d)
    {
        if (d != MONDAY && d != TUESDAY && d != WEDNESDAY && d != THURSDAY &&
            d != FRIDAY && d != SATURDAY && d != SUNDAY)
        {
            throw TimingException("Invalid day", TimingException::INVALID_DAY);
        }
        day = d;
    }

    Timing::Timing(const string &d, const Time &s, const Time &du)
        : day(d), start(s), duration(du)
    {
    }

    Timing::Timing()
    {
        setDay("default");
    }

    Timing::~Timing()
    {
    }

    void Timing::display() const
    {
        cout << "Jour     => " << day << "\n";
        start.display();
        duration.display();
    }
    Timing &Timing::operator=(const Timing &t)
    {
        setDay(t.getDay());
        setStart(t.getStart());
        setDuration(t.getDuration());
        return (*this);
    }
    int Timing::operator<(const Timing &t)
    {
        return compT(t) == -1;
    }
    int Timing::operator>(const Timing &t)
    {
        return compT(t) == 1;
    }
    int Timing::operator==(const Timing &t)
    {
        return compT(t) == 0;
    }
    int Timing::compT(const Timing &t)
    {
        if (day < t.day)
            return -1;
        if (day > t.day)
            return 1;
        if (start < t.start)
            return -1;
        if (start > t.start)
            return 1;
        if (duration < t.duration)
            return -1;
        if (duration > t.duration)
            return 1;
        return 0;
    }
}
