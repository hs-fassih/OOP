#include <iostream>
using namespace std;
class abstract1
{
private:
    int ab, cd;

public:
    virtual void print() = 0; //  pure virtual function
    virtual void fun() = 0;   // pure vitual function
    abstract1();
    ~abstract1();
};
abstract1::abstract1()
{
    cout << "\nInside abstract1 constructor";
}
abstract1::~abstract1()
{
    cout << "\nInside abstract1 destructor";
}
////////////////////////////////////////////////
class Grand : public abstract1
{
private:
    int g;

public:
    Grand(int x = 1);
    void print();
    void fun();
    ~Grand();
};
Grand::Grand(int x)
{
    cout << "\nInside Grand constructor";
    g = x;
}
void Grand::print()
{
    cout << "\nInside Grand print\n"
         << "g is " << g;
}
void Grand::fun()
{
    cout << "\nInside Grand fun";
}
Grand::~Grand()
{
    cout << "\nInside Grand destructor";
}
///////////////////////////////////////////////
class Alpha : public Grand
{
private:
    int a;

public:
    Alpha(int x = 1, int y = 1);
    void print();
    void EIDMUBARAK();
    ~Alpha();
};
Alpha::Alpha(int x, int y) : Grand(y)
{
    cout << "\nInside Alpha constructor";
    a = x;
}
void Alpha::print()
{
    cout << "\nInside Alpha print"
         << "\na is " << a << endl;
}
void Alpha::EIDMUBARAK()
{
    cout << "\nEnjoy your EID";
}
Alpha::~Alpha()
{
    cout << "\nInside Alpha Destructor";
}
/////////////////////////////////////////////////
class Beta : public Alpha
{
private:
    int b;

public:
    Beta(int x = 1, int y = 1, int z = 1);
    virtual void print();
    void fun();
    ~Beta();
};
Beta::Beta(int x, int y, int z) : Alpha(y, z)
{
    cout << "\nInside Beta Constructor";
    b = x;
}
// virtual void Beta::print()
void Beta::print()
{
    cout << "\nInside Beta print\n"
         << "b is " << b;
}
void Beta::fun()
{
    cout << "\nWhat is funny\n";
}
Beta::~Beta()
{
    cout << "\nInside Beta Destructor";
}
//////////////////////////////////////////////////
class child : public Beta
{
private:
    int c;

public:
    child(int c1 = 1, int c2 = 1, int c3 = 1, int c4 = 1);
    void print();
    ~child();
};
child::child(int c1, int c2, int c3, int c4) : Beta(c2, c3, c4)
{
    cout << "\nInside Child Constructor";
    c = c1;
}
void child::print()
{
    cout << "\nInside Child print\n"
         << "c is " << c;
}
child::~child()
{
    cout << "\nInside Child Destructor";
}
int main()
{
    child c1(1, 2, 3, 4);
    // Grand G1;
    // G1.child::print();    error
    // c1.print();
    child *p;
    // p = &G1;              error
    // p = new Grand;        error
    // p = new child;
    abstract1 *p1[4];
    p1[0] = &c1;
    p1[0]->print();
    p1[0]->fun();
}