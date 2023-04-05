#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class Player
{
private:
    string name;
    int id, score[5] = {0};
    float average;

public:
    Player();
    void setScores();
    float calAverage(void);
    float getAverage();
    void setid(int Id);
    int getid();
    void setname(int Name);
    string getname();
    void printinfo(Player P);
    Player(string Name, int Id);
    // Player(string = "Fassih", int = 123);        how to use default parameter
    ~Player();
};
Player::Player()
{
    cout << "\nCurrently inside a non-parameterized constructor";
}
void Player::setScores()
{
    srand(time(0));
    for (int j = 0; j < 5; j++)
    {
        score[j] = rand() % 10;
    }
}
float Player::calAverage(void)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += score[i];
    }
    average = sum / 5.0;
}
float Player::getAverage()
{
    return average;
}
void Player::setid(int Id)
{
    id = Id;
}
int Player::getid()
{
    return id;
}
void Player::setname(int Name)
{
    name = Name;
}
string Player::getname()
{
    return name;
}
void Player::printinfo(Player P)
{
    cout << "Player name:\t" << P.name << '\n'
         << "Player ID:\t" << P.id << "\nscores:\t\t";
    for (int k = 0; k < 5; k++)
    {
        cout << P.score[k] << ' ';
    }
    cout << "\nAverage:\t" << setprecision(5) << P.average;
}
Player::Player(string Name, int Id)
{
    name = Name;
    id = Id;
}
Player::~Player() {}
int main()
{
    string Name;
    int Id;
    cout << "Write the name and id of the player:\n";
    cin >> Name >> Id;
    Player p1(Name, Id);
    p1.setScores();
    p1.calAverage();
    cout << "Write the name and id of the player:\n";
    cin >> Name >> Id;
    Player p2(Name, Id);
    p2.setScores();
    p2.calAverage();
    cout << "Write the name and id of the player:\n";
    cin >> Name >> Id;
    Player p3(Name, Id);
    p3.setScores();
    p3.calAverage();
    cout << "\nThe player info is as follows\n";
    p1.printinfo(p1);
    cout << endl;
    p1.printinfo(p2);
    cout << endl;
    p1.printinfo(p3);
}