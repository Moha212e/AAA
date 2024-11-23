#include "Timing.h"
using namespace std;

namespace planning
{
    // Static constants for days of the week
    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    // Getter methods
    Time Timing::getDuration() const
    {
        return duration;
    }

    string Timing::getDay() const     // Marked as const, since it doesn't modify the object
    {
        return day;
    }

    Time Timing::getStart() const
    {
        return start;
    }

    // Setter methods
    void Timing::setStart(const Time &e)
    {
        start = e;
    }

    void Timing::setDuration(const Time &e)
    {
        duration = e;
    }

    void Timing::setDay(const string& d)  // Pass string by const reference
    {
        day = d;
    }   

    // Constructor with parameters
    Timing::Timing(const string& d, const Time &s, const Time &du)
        
    {
        day = d;
        start = s;
        duration =du;
    }

    // Default constructor
    Timing::Timing()
    {
        setDay("default");
    }

    // Destructor
    Timing::~Timing()
    {
    }

    // Display method
    void Timing::display() const
    {
        cout << "Jour     => " << day << "\n";
        start.display();     // Assuming Time class has a display() method
        duration.display();  // Assuming Time class has a display() method
    }
}