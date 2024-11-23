#include <string>      
#include <iostream>
#include <cstdlib>     
#include "Time.h" 
#ifndef TIMING_H 
#define TIMING_H 
using namespace std;   

namespace planning
{
    class Timing
    {
    private:
        string day;
        Time start;
        Time duration;

    public:
        static const string MONDAY;
        static const string TUESDAY;
        static const string WEDNESDAY;
        static const string THURSDAY;
        static const string FRIDAY;
        static const string SATURDAY;
        static const string SUNDAY;

        Timing();
        ~Timing();

        void display() const;
        void setDay(const string& d);   
        void setStart(const Time &e);
        void setStart(int h, int m);    
        void setDuration(const Time &e);
        
        string getDay() const;         
        Time getStart() const;
        Time getDuration() const;

        Timing(const string& d, const Time &s, const Time &du);
    };
}
#endif