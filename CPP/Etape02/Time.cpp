#include "Time.h"
namespace planning
{
    Time::Time(int d)
    {
        int h = d / 60;
        int m = d % 60;

        setHour(h);
        setMinute(m);
    }

    Time::Time(int h, int m)
    {
        setMinute(m);
        setHour(h);
    }
    int Time::getHour() const
    {
        return hour;
    }
    int Time::getMinute() const
    {
        return minute;
    }

    Time::Time(/* args */)
    {
        setHour(0);
        setMinute(0);
    }

    Time::~Time()
    {
    }









    
    void Time::setHour(int h)
    {
        hour = h;
    }
    void Time::setMinute(int m)
    {
        minute = m;
    }
    void Time::display() const
    {
        cout << "Heure    => " << hour << "h\n";
        cout << "Minute   => " << minute << "m\n";
    }
}