#include <stdio.h>
using namespace std;
#include <string.h>
#include <iostream>
class Event
{
private:
    int code;
    char *title;

public:
    Event();
    Event(int, const char *);
    int getCode() const;
    const char *getTitle() const;
    void setCode(int);
    void setTitle(const char *);
    ~Event();
    void display() const;
    Event(const Event &e);
};
