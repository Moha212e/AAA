#include <cstring>
#include <iostream>

using namespace std;

class Event
{
private:
    int code;
    char *title;

public:
    Event();
    Event(int c, const char* t);
    ~Event();
    void setCode(int c);
    void setTitle(const char* t);
    int getCode();
    const char* getTitle();
    void display();
    Event(Event&e);
};
Event::Event(Event&e){
    title =nullptr;
    setTitle(e.title);
    setCode(e.code);
}
Event::Event()
{
    code = 1;
    title = new char[strlen("default") + 1];
    strcpy(title, "default");
}

Event::Event(int c, const char* t)
{
    setCode(c);
    title = nullptr;
    setTitle(t);
}

Event::~Event()
{

        delete[] title;
    
}

void Event::setCode(int c)
{
    if (c > 0)
    {
        code = c;
    }
}

void Event::setTitle(const char* t)
{
    if (title != nullptr)
    {
        delete[] title;
    }
    title = new char[strlen(t) + 1];
    strcpy(title, t);
}

int Event::getCode()
{
    return code;
}

const char* Event::getTitle()
{
    return title;
}

void Event::display()
{
    cout << "Titre => " << title << "\n";
    cout << "Code  => " << code << "\n";
}
