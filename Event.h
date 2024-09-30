#include <string.h>

class Event

{

private:
  int code;
  char *title;
  Timing setTiming;
public:
void setTiming(const Timing &timing) {
        setTiming = timing;
    }
  Event()
  {
    title = new char[20];
    code = 1;
    strcpy(title, "default");
    setTiming = Timing("Default",Time(0,0),Time(0));

  }
  Event(const char *t,const int c , const Time &set){
    title = new char [20];
    code =0;
    strcpy(title, t);
    setTiming = set;
  }

  void display()
  {
    cout << "title = " << title << endl;
    cout << "Code  = " << code << endl;
    
  }
  void setCode(int c)
  {
    if (c < 0)
    {
      return;
    }
    code = c;
  }
  void setTitle(const char *t)
  {
    if (strlen(t) == 0)
    {
      return;
    }
    delete[] title;
    title = new char[strlen(t) + 1];
    strcpy(title, t);
  }
  int getCode()
  {
    return code;
  }
  char *getTitle()
  {
    return title;
  }
  Event(int c, const char *t)

  {
    code = c;
    title = nullptr;
    setTitle(t);
    strcpy(title, t);
  }
  Timing &getTiming (){
    return setTiming;
  }
  
};
