class Timing
{
private:
    string day;
    Time start;
    Time duration;

public:
    Timing();
    ~Timing();
    void display();
    void setDay(string d);
    void setStart(const Time &e);
    Time setStart(int h, int m);
    void setDuration(const Time &e);
    string getDay();
    Time getStart() const;
    Time getDuration() const;
    Timing(const string d,const Time &s,const Time &du);
    
};

Time Timing::getDuration() const
{
    return duration;
}

string Timing::getDay()
{
    return day;
}
Time Timing::getStart() const
{
    return start;
}
void Timing::setStart(const Time &e)
{
    start = e;
}
void Timing::setDuration(const Time &e)
{
    duration = e;
}
void Timing::setDay(string d)
{
    day = d;
}
Timing::Timing(const string d,const Time&s,const Time&du){
    day =d;
    start = s;
    duration = du;
}
Timing::Timing()
{
    setDay("default");
}

Timing::~Timing()
{
}
void Timing::display()
{
    cout << "Jour     => " << day << " \n";
    start.display();
    duration.display();
}
