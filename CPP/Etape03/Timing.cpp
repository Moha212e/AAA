#include "Timing.h"
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
    int Timing::compT(const Timing &x)
    {
        if(x.day == "Lundi")
            return 1;
        if(x.day == "Mardi")
            return 2;
        if(x.day == "Mercredi")
            return 3;
        if(x.day == "Jeudi")
            return 4;
        if(x.day == "Vendredi")
            return 5;
        if(x.day == "Samedi")
            return 6;
        if(x.day == "Dimanche")
            return 7;
        return -1; //erreur
    }
}
