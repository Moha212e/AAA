#include "Schedulable.h"
class Classroom : public Schedulable
{

private:
    string name;
    int seatingCapacity;

public:
    Classroom();
    Classroom(int i, string n, int s);
    Classroom(const Classroom &c) = default;

    ~Classroom() = default;

    void setName(string n);
    void setSeatingCapacity(int s);

    string getName() const;
    int getSeatingCapacity() const;
    int getId()const;
    string toString() const override;
    string tuple() const override;

    Classroom &operator=(const Classroom &c);

    friend std::ostream &operator<<(std::ostream &os, const Classroom &c);

    friend std::istream &operator>>(std::istream &is, Classroom &c);
};