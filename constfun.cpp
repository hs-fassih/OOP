#include <iostream>
using namespace std;
class player
{
private:
    int Id;
    char name;
    int Scores[5];
    float Average;

public:
    player(int = 0, char = 'a', int[] = NULL, float = 0.0);
    float calAverage(void);
    void print() const; // this is constant funation
    void setId(int);
    void setName(char);
    void setScores(int[]);
    int getID(void);
    char getName(void);
    float getAverage(void);
    ~player();
};
player::player(int i, char n, int s[], float a)
{
    // cout << "\nInside parameterized Constructor";
    Id = i;
    name = n;
    if (s == NULL)
    {
        cout << "\nEnter 5 score values";
        for (int i = 0; i < 5; i++)
        {
            cin >> Scores[i];
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            Scores[i] = s[i];
        }
    }
    Average = a;
}

float player::calAverage(void)
{
    // cout << "\nInside CalculateAverage() Function\n";
    int s = 0;
    for (int i = 0; i < 5; i++)
    {
        s += Scores[i];
    }
    Average = s / 5.0;
    return Average;
}
void player::print() const
{
    // cout << "\nInside print() function";
    cout << "\n\n Name of player is: " << name;
    cout << "\n ID of player is: " << Id;
    cout << "\n Scores of player is: ";
    for (int i = 0; i < 5; i++)
    {
        cout << Scores[i] << " ";
    }
    cout << endl;
    cout << "Average of player is: " << Average;
}
void player::setId(int i)
{
    // cout << "\nInside setId() function";
    Id = i;
}
void player::setName(char c)
{
    // cout << "\nInside setName() function";
    name = c;
}
void player::setScores(int s[])
{
    // cout << "\nInside setScores() function";
    for (int i = 0; i < 5; i++)
    {
        Scores[i] = s[i];
    }
}
int player::getID()
{
    // cout << "\nInside getId() function\n";
    return Id;
}
char player::getName(void)
{
    // cout << "\nInside getName() function\n";
    return name;
}
float player::getAverage()
{
    // cout << "\nInside getAverage() function\n";
    calAverage();
    return Average;
}
player::~player()
{
    // cout << "\nInside Destructor that does nothing\n";
}
int main()
{
    player p1;
    p1.print();
    p1.calAverage();
    p1.print();
}