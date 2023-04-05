#include <iostream>
using namespace std;
class Main1
{
public:
    void Function()
    {
        cout << "This is the main Class";
    }
};
class Main2
{
public:
    void Function2()
    {
        cout << "\nThis is another main Class";
    }
};
class Derived : public Main1, public Main2
{
};
int main()
{
    Derived Object;
    Object.Function();
    Object.Function2();
    return 0;
}