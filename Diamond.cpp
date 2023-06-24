#include <iostream>
using namespace std;
class Grand
{
    int g;

public:
    Grand(int x = 10)
    {
        cout << "\nIN Grand class constructor\n";
        g = x;
    }
    void print()
    {
        cout << "\nIN Grand class Print";
        cout << "\n g is : " << g;
    }
    ~Grand()
    {
        cout << "\nIN Grand class Destructor\n";
    }
};
class Alpha : public virtual Grand
{
    int a;

public:
    Alpha(int x = 1)
    {
        cout << "\nIN Alpha class constructor\n";
        a = x;
    }
    /*
    void print()
    {
        cout << "\nIN Alpha class Print";
        cout << "\n a is : " << a;
    }
    */
    ~Alpha()
    {
        cout << "\nIN Alpha class Destructor\n";
    }
};
class Beta : public virtual Grand
{
    int b;

public:
    Beta(int y = 1)
    {
        cout << "\nIN Beta class constructor\n";
        b = y;
    }
    /*
    void print()
    {
        cout << "\nIN Beta class Print";
        cout << "\n b is : " << b;
    }
    */
    ~Beta()
    {
        cout << "\nIN Beta class Destructor\n";
    }
};
class child : public Alpha, public Beta
{
    int c;

public:
    child(int c1 = 1, int c2 = 1, int c3 = 1) : Beta(c3), Alpha(c2)
    {
        cout << "\nIN child class constructor\n";
        c = c1;
    }
    /*
    void print()
    {
        cout << "\nIN Child class Print";
        cout << "\n c is : " << c;
        void print();
    }
    */
    ~child()
    {
        cout << "\nIN child class Destructor\n";
    }
};
int main()
{
    child c1(1, 2, 3);
    // c1.Alpha::print(); //  calling the function with the path explicitly for diamond solution
    // c1.Beta::print();
    // c1.Alpha::print(); //  function over-riding
    c1.print(); // this call is due to virtuallization
}