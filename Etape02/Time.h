#include <cstring>
#include <iostream>
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
Time::Time(int d)
{
    int h = 0;

    while (d > 60)
    {
        d = d%60;
        h++;
    }
    setHour(h);
    setMinute(d);
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