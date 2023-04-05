#include <iostream>
using namespace std;
class Company
{
public:
    string state1 = "\tIf it is comparable,\n";
    void president()
    {
        cout << "Stephan Winkleman:\n";
    }
};
class Car : public Company
{
public:
    string state2 = "\tit is no longer a ''BUGATTI''\n";
};
int main()
{
    Car myCar;
    myCar.president();
    cout << myCar.state1 + "" + myCar.state2;
}