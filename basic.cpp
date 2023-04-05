#include<iostream>
#include<iomanip>
using namespace std;
class University
{
private:
    /* data */
public:
    string roll, degree, name;
    char section;
    int grade;
    
    void Info(string Name, string Degree, string Roll, char Section, int Grade)         // Method definition INSIDE
    {
        cout << "Name: " << Name << "\n" << "Degree name: " << Degree << "\n" << "Roll.no: " << setw(10) << setfill(' ') << "" << Roll << "\n" << "Section: " << setw(17) << setfill(' ') << "" << Section << "\n" << "Grade Obtained: " << setw(10) << setfill(' ') << ""  << Grade << endl;
    }
    /*
    University(string Name, string Degree, string Roll, char Section, int Grade)         // Constructor
    {
        cout << "Name: " << Name << "\n" << "Degree name: " << Degree << "\n" << "Roll.no: " << setw(10) << setfill(' ') << "" << Roll << "\n" << "Section: " << setw(17) << setfill(' ') << "" << Section << "\n" << "Grade Obtained: " << setw(10) << setfill(' ') << ""  << Grade << endl;
    }
    */
};
/*                      Method definition OUTSIDE
void University::Info(string Name, string Degree, string Roll, char Section, int Grade)
{
    cout << "Name: " << Name << "\n" << "Degree name: " << Degree << "\n" << "Roll.no: " << Roll << "\n" << Section << "\n" << Grade << endl;
}
*/
int main()
{
    //University student = University("Syed Fassih ul Hassny", "Cybersecuirity", "22I-1730", 'A', 4);     // Constructor called at line 19
    University student;
    student.name = "Syed Fassih ul Hassny";
    student.roll = "22I-1730";
    student.grade = 4.00;
    student.degree = "Cybersecuirity";
    student.section = 'A';
    student.Info(student.name, student.degree, student.roll, student.section,student.grade);              // Method called at line 14
   return 0;
}