#include<iostream>
using namespace std;
class Employee
{
private:
    int salary;
    string name;
public:
    void setsalary(int s)
    {
        salary = s;
    }
    int getsalary()
    {
        return salary;
    }
    void setname(string n)
    {
        name = n;
    }
    string getname()
    {
        return name;
    }
    void Intro()
    {
        cout << "The employee name is " << name << " and his salary is = Rs/" << salary << endl;
    }
    /*
    Employee(string Name, int Salary)
    {
        name = Name;
        salary = Salary;
    }
    */
};
int main()
{
    Employee emp1;
    string employename;
    int pay;
    cout << "What is the name of the person: ";
    cin >> employename;
    cout << "\nJow much is his salary: ";
    cin >> pay;
    //  Employee emp1 = Employee(employename,pay);
    emp1.Intro();
    return 0;
}