#include <iostream>
class Time
{
private:
  int hour;
  int minute;
  int duration;

public:
  Time()
  {
    hour = 0;
    minute = 0;
    duration =0;
  }

  void display() const
  {
    cout << hour << "h" << minute << endl;
  }
  void setHour(int h)
  {
    if (h > 24 || h < 0)
    {
      return;
    }
    hour = h;
  }
  void setMinute(int m)
  {
    if (m > 60 || m < 0)
    {
      return;
    }
    minute = m;
  }
  int getHour()
  {
    return hour;
  }
  int getMinute()
  {
    return minute;
  }

  Time(int h, int m)
  {
    hour = h;
    minute = m;
  }
  
};