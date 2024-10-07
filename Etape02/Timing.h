class Timing
{
private:
    char * day;
    Time start;
    Time duration;
public:
    Timing();
    ~Timing();
    void display ();
    void setDay(char* d);
    void setStart(Time &e);
    Time setStart(int h,int m);
};
Time Timing::setStart(int h,int m){
    
}
void Timing::setStart(Time &e){
    
}
void Timing::setDay(char* d){
    day = new char [strlen(d)+1];
    strcpy(day,d);
}

Timing::Timing()
{
    setDay("default");

}

Timing::~Timing()
{
}
void Timing::display(){
    cout<<"Jour     => "<<day<<" \n";
    
}
