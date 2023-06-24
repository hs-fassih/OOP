#include <iostream>
using namespace std;
class Book
{
    int id, pages, prices;

public:
    static int count;
    virtual void print()
    {
        cout << "id: " << this->id << "\npages: " << this->pages << "\nprices: " << this->prices << endl;
    }
};
class shelf : public Book
{
public:
    void draw();
};
int main()
{
    // Book B_Array[3] = {{5, 600, 7000}, {6, 40}, {}};
    // B_Array[1].print();
    Book *ptr = new Book;
    Book *&ref = ptr;
    // b1.count = 10;
    // Book::count = 5;
    shelf s1;
}