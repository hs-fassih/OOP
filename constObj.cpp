#include <iostream>
#include <ctime>
using namespace std;
class player
{
    int Id;
    // char name;
    string name;
    int size;
    int *Scores;
    float Average;

public:
    player(int = 0, string = "fassih", int s = 2, int * = NULL);
    float calAverage(void);
    void print() const;
    void setId(int);
    void setName(string);
    void setsize(int);
    void setScores(int *); // interesting
    int getID(void) const;
    string getName(void) const;
    float getAverage(void);
    int getsize(void) const;
    // How to write getscores function ?????
    ~player();
};
player::player(int i, string n, int s, int *arr) // Q. Default Constructor with default parameters
{
    srand(time(0));
    // cout << "\nInside parameterized Constructor";
    Id = i;
    name = n;
    size = s;
    if (arr == NULL)
    {
        Scores = new int[size];
        cout << "Enter values for student:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> Scores[i];
        }
    }
    else
    {
        Scores = new int[size];
        cout << "Enter values of " << size << " students";
        for (int i = 0; i < size; i++)
        {
            cin >> Scores[i];
        }
    }
    // cout << "\nEnter the name again: ";           non-constant function called by a constant object( only through contructor )
    // cin >> n;
    // setName(n);
    player::calAverage();
}
float player::calAverage(void)
{
    // cout << "\nInside CalculateAverage() Function\n";
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += Scores[i];
    }
    Average = float(s) / size;
    return Average;
}
void player::print() const
{
    cout << "\n................................";
    // cout << "\nInside print() function";
    cout << "\nName of player is : " << name;
    cout << "\nID of player is : " << Id;
    cout << "\nTotal matches played are : " << size;
    cout << "\nScores of player is: ";
    for (int i = 0; i < size; i++)
    {
        cout << Scores[i] << " ";
    }
    cout << endl;
    cout << "\nAverage of player is: " << Average;
    cout << "\n................................\n";
}
void player::setId(int i)
{
    // cout << "\nInside setId() function";
    Id = i;
}
void player::setName(string c)
{
    // cout << "\nInside setName() function";
    name = c;
}
void player::setsize(int s)
{
    // cout << "\nInside setsize() function";
    size = s;
}
void player::setScores(int *arr)
{
    // cout << "\nInside setScores() function";
    delete[] Scores;
    Scores = new int[size];
    for (int i = 0; i < size; i++)
    {
        Scores[i] = arr[i];
    }
}
int player::getID(void) const
{
    // cout << "\nInside getId() function\n";
    return Id;
}
string player::getName(void) const
{
    // cout << "\nInside getName() function\n";
    return name;
}
float player::getAverage() /// an interesting fact inside function
{
    // cout << "\nInside getAverage() function\n";
    calAverage();
    return Average;
}
int player::getsize(void) const
{
    return size;
}
player::~player()
{
    // cout << "\nInside Destructor that does nothing\n";
    delete[] Scores;
}
int main()
{
    int id, size;
    string n;
    cout << "Enter the name, id and size for the player:\n";
    cin >> n >> id >> size;
    const player p1(id, n, size);
    // p1.setName();      ERROR
    p1.print();
}