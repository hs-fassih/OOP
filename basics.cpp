#include <iostream>
#include <string>
using namespace std;
class Employee
{
    private:
        string Name;
        string Company;
        int Age;
    public:
        void setName(string name)                       // setter
        {
            Name = name;
        }
        string getName()                                // getter
        {
            return Name;
        }
        void setCompany(string company)                 // setter
        {
            Company = company;
        }
        string getCompany()                             // getter
        {
            return Company;
        }
        void setAge(int age)                            // setter
        {
            if(age>=18)                             // else instruction is followed
            {
                Age = age;
            }
        }
        int getAge()                                    // getter
        {
            return Age;
        }
        void Intro()                                    // setting behaviours
        {
            cout << "name - " << Name << endl;
            cout << "company - " << Company << endl;
            cout << "age - " << Age << endl;
        }
        Employee(string name, string company, int age)  // constructor
        {
            Name = name;
            Company = company;
            Age = age;
        }
};
int main()
{
    Employee employee1 = Employee("fassih", "Youtube", 18); // creating object of UD class and then instructing to the constructor
    /*employee1.name="Fassih";        // setting values
    employee1.company="TM";
    employee1.age=18;
    */
    employee1.Intro(); // performing behaviour
    Employee employee2 = Employee("James", "Amazon", 25);
    /*employee2.name="John";          // setting values
    employee2.company="AMazon";
    employee2.age=25;
    */
    employee2.Intro(); // another object of the same behaviour
    employee1.setAge(14);
    cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;
}