#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class Player
{
private:
    string name;
    int id, size;
    int *score;
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
    void printinfo(Player P, int strike);
    Player(string Name, int Id, int Strikes);
    // Player(string = "Fassih", int = 123);
    ~Player();
};
Player::Player()
{
    cout << "\nCurrently inside a non-parameterized constructor";
}
void Player::setScores()
{
    score = new int[size];
    srand(time(0));
    for (int j = 0; j < size; j++)
    {
        *(score + j) = rand() % 10;
    }
}
float Player::calAverage(void)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(score + i);
    }
    average = sum / ((size)*1.0);
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
void Player::printinfo(Player P, int strike)
{
    cout << "Player name:\t" << P.name << '\n'
         << "Player ID:\t" << P.id << "\nscores:\t\t";
    for (int k = 0; k < strike; k++)
    {
        cout << P.score[k] << ' '; // how to do this in pointer notation
    }
    cout << "\nAverage:\t" << setprecision(4) << P.average;
}
Player::Player(string Name, int Id, int Strikes)
{
    size = Strikes;
    name = Name;
    id = Id;
}
Player::~Player() // how to use destructor properly
{
    delete[] score;
    score = NULL;
}
int main()
{
    string Name;
    int Id, strikes;
    cout << "Write the name and id of the 1st player:\n";
    cin >> Name >> Id;
    cout << "Enter teh number of strikes: ";
    cin >> strikes;
    // Player p1(Name, Id, strikes);
    Player p1;
    p1.setScores();
    p1.calAverage();
    cout << "1st player info is as follows\n";
    p1.printinfo(p1, strikes);

    cout << "\n\nWrite the name and id of the 2nd player:\n";
    cin >> Name >> Id;
    cout << "Enter the number of strikes: ";
    cin >> strikes;
    Player p2(Name, Id, strikes);
    cout << endl;
    p2.setScores();
    p2.calAverage();
    cout << "2nd player info is as follows\n";
    p1.printinfo(p2, strikes);

    cout << "\n\nWrite the name and id of the 3rd player:\n";
    cin >> Name >> Id;
    cout << "Enter teh number of strikes: ";
    cin >> strikes;
    Player p3(Name, Id, strikes);
    p3.setScores();
    p3.calAverage();
    cout << "3rd player info is as follows\n";
    p1.printinfo(p3, strikes);

    p1.~Player();
    return 0;
}