#include <iostream>
using namespace std;
typedef unsigned long ulong; /*
Keyword   Data type   new name */
class Student
{
    ulong id;
    unsigned age;

public:
    unsigned GetAge() const
    {
        return age;
    }
    ulong GetId() const
    {
        return id;
    }
    void SetAge(unsigned n)
    {
        age = n;
    }
    void SetId(ulong n)
    {
        id = n;
    }
};
class Employee
{

private:
    unsigned age;
    ulong id;

public:
    unsigned GetAge() const
    {
        return age;
    }
    void SetAge(unsigned n)
    {
        age = n;
    }
    void SetId(ulong n)
    {
        id = n;
    }
    ulong GetId() const
    {
        return id;
    }
};
class Salaried : public Employee
{
    float salary;

public:
    float GetSalary() const
    {
        return salary;
    }
    void SetSalary(float s)
    {
        salary = s;
    }
};

class GradAssistant : public Student, public Salaried
{
public:
    void Display() const;
};

void GradAssistant::Display() const
{
    cout << Student::GetId() << "," << GetSalary() << "," << Salaried::GetAge(); // ambiguity resolved by explicit call
    // cout << GetId() << "," << GetSalary() << "," << GetAge();
}
int main(void)
{

    GradAssistant ga;
    ga.Student::SetAge(20); // ambiguity resolved by explicit call
    ga.Salaried::SetId(15); // ambiguity resolved by exlpicit call
    ga.Salaried::SetSalary(5000);
    // ga.SetAge(20); // ambiguity
    // ga.SetId(15);  // ambiguity
    ga.Display(); // ambiguity inside display function

} // program will compile and will generate NO errors