#include "planning.h"
namespace planning
{
    Timing Event::getTiming()
    {
        return timing;
    }
    void Event::setTiming(const Timing &t)
    {
        timing = t;
    }
    Event::Event(Event &e)
    {
        title = nullptr;
        setTitle(e.title);
        setCode(e.code);
    }
    Event::Event()
    {
        code = 1;
        title = new char[strlen("default") + 1];
        strcpy(title, "default");
    }

    Event::Event(int c, const char *t)
    {
        setCode(c);
        title = nullptr;
        setTitle(t);
    }

    Event::~Event()
    {

        delete[] title;
    }

    void Event::setCode(int c)
    {
        if (c > 0)
        {
            code = c;
        }
    }

    void Event::setTitle(const char *t)
    {
        if (title != nullptr)
        {
            delete[] title;
        }
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    int Event::getCode()
    {
        return code;
    }

    const char *Event::getTitle()
    {
        return title;
    }

    void Event::display()
    {
        cout << "Titre => " << title << "\n";
        cout << "Code  => " << code << "\n";
        timing.display();
    }

    Time Timing::getDuration() const
    {
        return duration;
    }

    string Timing::getDay()
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
    void Timing::setDay(string d)
    {
        day = d;
    }
    Timing::Timing(const string d, const Time &s, const Time &du)
    {
        day = d;
        start = s;
        duration = du;
    }
    Timing::Timing()
    {
        setDay("default");
    }

    Timing::~Timing()
    {
    }
    void Timing::display()
    {
        cout << "Jour     => " << day << " \n";
        start.display();
        duration.display();
    }

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
    int Time::getHour()
    {
        return hour;
    }
    int Time::getMinute()
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
    void Time::display()
    {
        cout << "Heure    => " << hour << "h\n";
        cout << "Minute   => " << minute << "m\n";
    }
}