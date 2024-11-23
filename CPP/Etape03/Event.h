#ifndef EVENT_H
#define EVENT_H
#include <stdio.h>
#include "Timing.h"
using namespace std;
#include <string.h>
#include <iostream>
namespace planning
{
    class Event
    {
    private:
        int code;
        char *title;
        Timing *timing;

    public:
        static int currentCode;
        Event();
        Event(int, const char *);
        int getCode() const;
        const char *getTitle() const;
        void setCode(int);
        void setTitle(const char *);
        ~Event();
        void display() const;
        Event(const Event &);
        void setTiming(const Timing &);
        const Timing getTiming() const;
    };
}
#endif