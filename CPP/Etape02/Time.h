#ifndef TIME_H
#define TIME_H
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

namespace planning
{
    class Time
    {
    private:
        int hour;
        int minute;

    public:
        // Constructors
        Time();                  
        Time(int d);             
        Time(int h, int m);      

        // Destructor
        ~Time();

        // Setters
        void setHour(int h);
        void setMinute(int m);

        // Getters
        int getHour() const;
        int getMinute() const;

        // Display function
        void display() const;
    };
}

#endif // TIME_H
