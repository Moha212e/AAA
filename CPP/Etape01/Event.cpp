#include "Event.h"
#include <cstring>
#include <iostream>

using namespace std;

Event::Event()
{
	code = 0;
	title = new char[strlen("default") + 1];
	strcpy(title, "default");
}

Event::Event(int c, const char *t)
{
	code = c;
	title = nullptr;
	setTitle(t);
}

Event::Event(const Event &e)
{
	code = e.code;
	if (e.title)
	{
		title = new char[strlen(e.title) + 1];
		strcpy(title, e.title);
	}
	else
	{
		title = nullptr;
	}
}

Event::~Event()
{
	delete[] title;
}

int Event::getCode() const
{
	return code;
}

const char *Event::getTitle() const
{
	return title;
}

void Event::setCode(int c)
{
	code = c;
}

void Event::setTitle(const char *t)
{

	if (title != nullptr)
	{
		delete[] title;
	}

	if (t)
	{
		title = new char[strlen(t) + 1];
		strcpy(title, t);
	}
	else
	{
		title = nullptr;
	}
}

void Event::display() const
{
	cout << "Code = " << code << endl;
	cout << "Title = " << (title ? title : "(null)") << endl;
}
