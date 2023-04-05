#include <iostream>
using namespace std;
class time
{
private:
    int sec, min, hour;

public:
    time(int a = 0, int b = 0, int c = 0);
    int gettime();
    void display();
    ~time();
};
time::time(int a, int b, int c)
{
    cout << "\nInside time constructor";
    sec = a;
    min = b;
    hour = c;
}
int time::gettime()
{
    return sec;
}
void time::display()
{
    cout << "\nThe time is " << sec << ":" << min << ":" << hour;
}
time::~time()
{
    cout << "\ninside time destructor";
}
class player
{
    int Id;            // //> .
    char name;         // //> .
    int size;          // //> non-static and non-constant data members
    int *Scores;       // //> .
    float Average;     // //> .
    static int count;  // static data members
    const char gender; // Constant data member

    class time join; // <<<<<< creating an object of time class to implement composition
public:
    player(int = 0, char = 'a', int s = 2, char = 'M', int = 1, int = 1, int = 1, int * = NULL); // Default parameterized constructor
    player(const player &);
    player &calAverage(void);
    player &print(void);
    void setId(int);
    void setName(char);
    void setsize(int);
    void setScores(int *);
    int getID(void) const;
    char getName(void) const;
    float getAverage(void);
    int getsize(void) const;
    // How to write getscores function ?????
    static void showcount() // static function
    {
        cout << "\nValue of count" << count;
    }
    ~player();
};
int player::count = 0; // assigning value to static data member of class
player::player(int i, char n, int s, char g, int hr, int mn, int sc, int *arr) : Id(i), join(hr, mn, sc), name(n), size(s), gender(g)
{
    cout << "\nInside parameterized player Constructor : \n";
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
    player::calAverage();
    count++;
}
player::player(const player &p) : gender(p.gender)
{
    cout << "\nIn Copy player Constructor\n";
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
}
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
    join.display();                                               // called display function of composition
    cout << "\nafter calling gettime, we get " << join.gettime(); // using getter of time in player
    return *this;
}
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
player::~player()
{
    cout << "\nInside player Destructor\n";
    delete[] Scores;
    count--;
}
int main()
{
    // class time t1(2, 2, 2);
    // t1.display();
    player p1(2, 'N', 3, 'F', 5, 3, 10); /// object of player for implementing composition
    p1.print();
}