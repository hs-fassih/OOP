#include <iostream>
using namespace std;
class Company
{
protected:
    int salary;
};
class Employee : public Company
{
public:
    int bonus;
    void setsalary(int s)
    {
        salary = s;
    }
    int getsalary()
    {
        return salary;
    }
};
int main()
{
    Employee person;
    person.setsalary(50000);
    person.bonus = 4000;
    cout << "the salary of the person is " << person.getsalary() << " and the bonus is " << person.bonus << endl;
}