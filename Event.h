class Event

{

private:
  int code;
  char *title;

public:
  Event()
  {
    title = new char[20];
    code = 1;
    strcpy(title, "default");
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
};
