#ifndef PLANNING_H
#define PLANNING_H

#include <iostream>
#include <cstring>
using namespace std;
namespace planning
{
    class Time
    {
    private:
        int hour;
        int minute;

    public:
        Time();
        Time(int d);
        ~Time();
        void setHour(int h);
        void setMinute(int m);
        void display();
        int getHour();

        int getMinute();
        Time(int h, int m);
    };
    class Event
    {
    private:
        int code;
        char *title;
        Timing timing;

    public:
        Event();
        Event(int c, const char *t);
        ~Event();
        void setCode(int c);
        void setTitle(const char *t);
        int getCode();
        const char *getTitle();
        void display();
        Event(Event &e);
        void setTiming(const Timing &t);
        Timing getTiming();
    };
    class Timing
    {
    private:
        string day;
        Time start;
        Time duration;

    public:
        Timing();
        ~Timing();
        void display();
        void setDay(string d);
        void setStart(const Time &e);
        Time setStart(int h, int m);
        void setDuration(const Time &e);
        string getDay();
        Time getStart() const;
        Time getDuration() const;
        Timing(const string d, const Time &s, const Time &du);
    };

}
#endif