#include <iostream>
using namespace std;
void printall(void); // A gloabal function which we make friend of player class
class player
{
    int Id;            //
    string name;       //
    int size;          // //> non-static and non-constant data members
    int *Scores;       //
    float Average;     //
    static int count;  // static data members
    const char gender; // Constant data member
public:
    player(int = 0, string = "fasih", int s = 2, char = 'N', int * = NULL);
    player &calAverage(void);
    void print(void);
    void setId(int);
    void setName(char);
    void setsize(int);
    void setScores(int *); // interesting
    int getID(void) const;
    string getName(void) const;
    float getAverage(void);
    int getsize(void) const;
    // How to write getscores function ?????
    static void showcount() // static function
    {
        cout << "\nValue of count" << count;
    }
    ~player();
    friend void printall(); // Granting printall() function as friend of class player
};
int player::count = 0; // assigning value to static data member of class
player::player(int i, string n, int s, char g, int *arr) : Id(i), name(n), size(s), gender(g)
{
    // cout << "\nInside parameterized Constructor";
    if (arr == NULL)
    {
        Scores = new int[size];
        cout << "Enter values for player";
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
    Average = 10;
    player::calAverage(); // calculating average in constructor
    count++;
}
player &player::calAverage(void)
{
    cout << count;
    cout << "\nInside CalculateAverage() Function\n";
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += Scores[i];
    }
    this->Average = float(s) / size;
    return *this;
}
void player::print()
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
    cout << "\nAverage of player is: " << this->Average;
    cout << "\n................................\n";
    // return *this;
}
//...... Setter or Mutator Functions ......
void player::setId(int i)
{
    // cout << "\nInside setId() function";
    Id = i;
}
void player::setName(char c)
{
    // cout << "\nInside setName() function";
    //  name = c;
}
void player::setsize(int s)
{
    // cout << "\nInside setsize() function";
    this->size = s;
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
// ..... Accessor or Getter functions .......
int player::getID(void) const
{
    // cout << "\nInside getId() function\n";
    return this->Id;
}
string player::getName(void) const
{
    // cout << "\nInside getName() function\n";
    return name;
}
float player::getAverage() /// an interesting fact inside function
{
    // cout << "\nInside getAverage() function\n";
    player::calAverage();
    return Average;
}
int player::getsize(void) const
{
    return (*this).size;
}
player::~player()
{
    // cout << "\nInside Destructor that does nothing\n";
    delete[] Scores;
    count--;
}
// Read this function carefully and implement it in main
void printall()
{
    // cout << "\n......Inside printall() global function.......\n";
    player p;
    cout << "\n................................";
    cout << "\nInside print() function";
    cout << "\nName of player is : " << p.name;
    cout << "\nID of player is : " << p.Id;
    cout << "\nTotal matches played are : " << p.size;
    cout << "\nScores of player is: ";
    for (int i = 0; i < p.size; i++)
    {
        cout << p.Scores[i] << " ";
    }
    cout << endl;
    cout << "\nAverage of player is: " << p.Average;
    cout << "\n................................\n";
}
int main()
{
    // write your implementstion code here
    int id, size;
    string n;
    cout << "Enter the name, id and size for the player:\n";
    cin >> n >> id >> size;
    player p1(id, n, size);
    p1.calAverage().print(); /// cascading call enabled by using this pointer see defination of functions
}