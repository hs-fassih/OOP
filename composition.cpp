#include <iostream>
using namespace std;
class time
{
    int hour, min, sec;

public:
    time(int a = 1, int b = 1, int c = 1)
    {
        cout << "\nIn Time Constructor\n ";
        hour = a;
        min = b;
        sec = c;
    }
    void display()
    {
        cout << "\nIn Time Display()\n ";
        cout << hour << ":" << min << ":" << sec << endl;
    }
    ~time()
    {
        cout << "\nTIME Destructor called\n\n";
    }
    ////Implement Setter getter and other utility functions here
};
class player /// parent/super/Base class
{
protected:
    int Id; // //> .
private:
    char name;         // //> .
    int size;          // //> non-static and non-constant data members
    int *Scores;       // //> .
    float Average;     // //> .
    static int count;  // static data members
    const char gender; // Constant data member
    class time join;   // creating an object of time class to implement composition
public:
    player(int = 0, char = 'a', int s = 2, char = 'M', int = 1, int = 1, int = 1, int * = NULL); // Default parameterized constructor
    /*player():gender('M')//default constructor discuss during lecture
    {
    cout << "\nPLayer DC\n";
    }*/
    ////Copy constructor//discuss during lecture
    // player(const player&);
    //  ....... Utility Functions ........
    player &calAverage(void);
    player &print(void);
    //...... Setter or Mutator Functions ......
    void setId(int);
    void setName(char);
    void setsize(int);
    void setScores(int *); // interesting
    // ..... Accessor or Getter functions .......
    int getID(void) const;
    char getName(void) const;
    float getAverage(void);
    int getsize(void) const;
    // How to write getscores function ?????
    static void showcount() // static function
    {
        // cout << name;
        cout << "\nValue of count" << count;
    }
    ~player(); // Destructor
};
//////////////////////// . . . define class functions out of line/scope . . . ////////
int player::count = 0;                                                                                                                // assigning value to static data member of clas
player::player(int i, char n, int s, char g, int hr, int mn, int sc, int *arr) : Id(i), join(hr, mn, sc), name(n), size(s), gender(g) // Constant data member and composition mustneed intilizer with constructor
{
    cout << "\nInside parameterized Constructor of Player Class : \n";
    if (arr == NULL)
    {
        Scores = new int[size];
        cout << "Enter values of " << size << " player : ";
        for (int i = 0; i < size; i++)
        {
            cin >> Scores[i];
        }
    }
    else
    {
        Scores = new int[size];
        cout << "Enter values of " << size << " students : ";
        for (int i = 0; i < size; i++)
        {
            cout << "\nEnter " << i + 1 << " Value : ";
            cin >> Scores[i];
        }
    }
    player::calAverage(); // calculating average in constructor
    count++;
}
/// Defination of copy constructor
////Copy constructor
/*player::player(const player & p) :gender(p.gender)
{
cout << "\nIn Copy Constructor\n";
this->Id = p.Id;
this->size = p.size;
this->Scores = new int[this->size];
cout << "\nEnter " << size << " Values for scores";
for (int i = 0; i < this->size; i++)
{
cout << "\nEnter " << i + 1 << " Value : ";
cin >> this->Scores[i];
}
player::calAverage();
count++;
}*/
// ....... Utility Functions ........
player &player::calAverage(void)
{
    cout << "\nInside CalculateAverage() Function\n";
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += Scores[i];
    }
    this->Average = float(s) / size;
    return *this;
}
player &player::print()
{
    cout << "\n................................";
    cout << "\nInside print() function";
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
    join.display(); /// called display function of composition
    return *this;
}
//...... Setter or Mutator Functions ......
void player::setId(int i)
{
    cout << "\nInside setId() function";
    Id = i;
}
void player::setName(char c)
{
    cout << "\nInside setName() function";
    // name = c;
}
void player::setsize(int s)
{
    cout << "\nInside setsize() function";
    this->size = s;
}
void player::setScores(int *arr)
{
    cout << "\nInside setScores() function";
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
    cout << "\nInside getId() function\n";
    return this->Id;
}
char player::getName(void) const
{
    cout << "\nInside getName() function\n";
    return name;
}
float player::getAverage() /// an interesting fact inside function
{
    cout << "\nInside getAverage() function\n";
    player::calAverage();
    return Average;
}
int player::getsize(void) const
{
    return (*this).size;
}
// Definition of Destructor
player::~player() // Destructor
{
    cout << "\nInside Destructor that Delete Dynamic Memory\n";
    delete[] Scores;
    count--;
}
class cricketPlayer : public player // child / sub / derived class
{
    int ranking;

public:
    cricketPlayer(int i = 1, char n = 'N', int s = 2, char g = 'M', int hr = 1, int mn = 1, int sc = 1, int r = 1, int *arr = NULL) : player(i, n, s, g, hr, mn, sc, arr)
    {
        cout << "\nIn Crickerplayer Default Parameterized Constructor";
        ranking = r;
        Id = 10;
    }
    ~cricketPlayer()
    {
        cout << "\nIn Crickerplayer Destructor";
    }
    void print()
    {
        cout << "\n\nIN CPPF";
        player::print();
        cout << "\nRanking " << ranking;
    }
};
int main()
{
    // class time t1(2, 2, 2);
    // t1.display();
    // player p1(2, 'N', 3, 'F', 5, 3, 10);///object of player for implementingcomposition
    // p1.print();
    cricketPlayer p1;
    p1.print(); // p1.cricketPlayer::print();
    p1.player::print();
    // p1.player::print();
    // cricketPlayer r1(3,'A',3,'F',5,6,7,1);
    // r1.cricketPlayer::print();///see what will happen here
    // r1.player::print();
    // cout << "\n\nSize of player = " << sizeof(p1) << endl << endl;
    // cout << "\n\nSize of Cricketplayer = " << sizeof(r1) << endl << endl;
}