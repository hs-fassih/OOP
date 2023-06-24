#include <iostream>
using namespace std;
class Base
{
public:
    virtual void show()
    {
        cout << "\nIn the base show";
    }
};
class Derived1 : public Base
{
public:
    void show()
    {
        cout << "\nIn the derived 1 show";
    }
};
class Derived2 : public Base
{
public:
    void show()
    {
        cout << "\nInside derived 2 show";
    }
};
int main()
{
    /*
    Base b1;
    b1.show();
    Derived1 d1;
    d1.show();
    Base *pb = &b1;
    pb->show();
    pb = &d1;
    // pb->Base::show();
    pb->show();
    */
    Derived1 d1;
    Derived2 d2;
    Base *pb;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n % 2)
        pb = &d1;
    else
        pb = &d2;
    pb->show();
    cout << "\n";
    // pb->Base::show();
}