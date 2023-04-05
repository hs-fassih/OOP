#include <iostream>
using namespace std;
class Player
{
private:
    int id;

public:
    void setid(int num)
    {
        id = num;
    }
    int getid()
    {
        return id;
    }
    int operator int()
    {
        return id;
    }
};
class Time
{
private:
    int join;
};
int main()
{
    int n, m;
    cout << "Enter the player id: ";
    cin >> n;
    Player p1;
    p1.setid(n);

    m = p1;
}