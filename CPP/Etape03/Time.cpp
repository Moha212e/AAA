
#include "Time.h"

using namespace std;

namespace planning
{
    // Constructeurs et destructeur
    Time::Time(int d)
    {
        int h = d / 60;
        int m = d % 60;
        setHour(h);
        setMinute(m);
    }

    Time::Time(int h, int m)
    {
        setHour(h);
        setMinute(m);
    }

    Time::Time()
    {
        setHour(0);
        setMinute(0);
    }

    Time::~Time() {}

    // Accesseurs
    int Time::getHour()const
    {
        return hour;
    }

    int Time::getMinute()const
    {
        return minute;
    }

    void Time::setHour(int h)
    {
        hour = h;
    }

    void Time::setMinute(int m)
    {
        minute = m;
    }

    // Affichage
    void Time::display() const
    {
        cout << "\nHeure    => " << hour << "h\n";
        cout << "\nMinute   => " << minute << "m\n";
    }

    // Surcharge des opérateurs
    Time Time::operator+(Time t)
    {
        Time resultat;
        resultat.hour = hour + t.hour;
        resultat.minute = minute + t.minute;

        if (resultat.minute >= 60)
        {
            resultat.minute -= 60;
            resultat.hour++;
        }

        return resultat;
    }

    Time &Time::operator=(const Time &t)
    {
        if (this != &t)
        {
            hour = t.hour;
            minute = t.minute;
        }
        return *this;
    }

    Time operator+(int n, const Time &t)
    {
        Time resultat = t;
        resultat.minute += n;

        if (resultat.minute >= 60)
        {
            resultat.minute -= 60;
            resultat.hour++;
        }

        return resultat;
    }

    Time Time::operator-(int m)
    {
        Time temp(*this);
        temp.minute = (temp.hour * 60) + temp.minute;
        temp.minute = temp.minute - m;
        temp.hour = temp.minute / 60;
        temp.minute = temp.minute % 60;

        return temp;
    }

    Time operator-(int m, const Time &t)
    {
        Time temp;
        temp.hour = m / 60;
        temp.minute = m % 60;
        m = (t.hour * 60) + t.minute;
        return temp - m;
    }

    Time Time::operator-(const Time &t2)
    {
        Time temp(*this);
        int m = (t2.hour * 60) + t2.minute;
        return temp - m;
    }

    int Time::operator<(const Time &t)
    {
        return comptH(t) == -1;
    }

    int Time::operator>(const Time &t)
    {
        return comptH(t) == 1;
    }

    int Time::operator==(const Time &t)
    {
        return comptH(t) == 0;
    }

    int Time::comptH(const Time &t)
    {
        if (hour < t.hour)
            return -1;
        if (hour > t.hour)
            return 1;
        if (minute < t.minute)
            return -1;
        if (minute > t.minute)
            return 1;
        return 0;
    }

    // Surcharge de l'opérateur >> pour l'entrée
    istream &operator>>(istream &s, Time &t)
    {
        int h, m;
        do
        {
            cout << "Saisie l'heure (0-23): ";
            s >> h;
            if (h < 0 || h >= 24)
            {
                cout << "Heure invalide. Veuillez entrer une heure entre 0 et 23.\n";
            }
        } while (h < 0 || h >= 24);
        t.setHour(h);

        do
        {
            cout << "Saisie la minute (0-59): ";
            s >> m;
            if (m < 0 || m >= 60)
            {
                cout << "Minute invalide. Veuillez entrer une minute entre 0 et 59.\n";
            }
        } while (m < 0 || m >= 60);
        t.setMinute(m);

        return s;
    }

    ostream &operator<<(ostream &s, const Time &t)
    {
        s << "Heure => " << t.getHour() << "h "
          << "Minutes => " << t.getMinute() << "m";
        return s;
    }

    // Opérateurs de pré-incrémentation et post-incrémentation
    Time Time::operator++()
    {
        (*this) = (*this) + 1;
        return (*this);
    }

    Time Time::operator++(int)
    {
        Time temp(*this);
        (*this) = (*this) + 1;
        return temp;
    }

    Time Time::operator--()
    {
        (*this) = (*this) - 1;
        return (*this);
    }

    Time Time::operator--(int)
    {
        Time temp(*this);
        (*this) = (*this) - 1;
        return temp;
    }
}
