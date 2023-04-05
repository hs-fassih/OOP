#include <iostream>
using namespace std;
class Continent // This is the Base class
{
public:
    void Parent(int num)
    {
        int ary[num][num] = {0};
        for (int i; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cout << i + j << " ";
            }
            cout << endl;
        }
    }
};
class Country : public Continent // This is the first level inheritance
{
};
class City : public Country // This is the second level inheritance
{
};
int main()
{
    City Person;
    int num;
    cout << "Enter the order of matrix: ";
    cin >> num;
    Person.Parent(num);
    return 0;
}