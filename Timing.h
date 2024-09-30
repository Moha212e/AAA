#include <string.h>

class Timing
{
private:
  char *day;
  int month;
  Time startTime;
  Time duration;

public:
  Timing()
  {
    day = new char[30];
    month = 0;
    startTime = Time(0, 0);
    duration = Time(0);
    strcpy(day, "default");
  }
  Timing(const char *d, const Time &start, const Time &dur)
  {
    day = new char[30];
    strcpy(day, d);
    startTime = start;
    duration = dur;
  }

  void display()
  {
    cout << "Jour : " << day << endl;
    cout << "Mois : " << month << endl;
    cout << "Debut : ";
    startTime.display();
    cout << "Duree : ";
    duration.display();
  }

  void setDay(const char *d)
  {
    if (strlen(d) == 0 || strlen(d) > 30)
      return;
    strcpy(day, d);
  }

  void setStart(const Time &t)
  {
    startTime = t;
  }

  void setDuration(const Time &t)
  {
    duration = t;
  }

  char *getDay()
  {
    return day;
  }

  Time &getStart()
  {
    return startTime;
  }

  Time &getDuration()

  {
    return duration;
  }
  Timing(const Timing &copie)
  {
    day = new char[30];
    strcpy(day, copie.day);
    month = copie.month;
    startTime = copie.startTime;
    duration = copie.duration;
  }
  ~Timing()
  {
    delete[] day; 
  }
};