#include <iostream>
using namespace std;
class Player
{
private:
    int id;
    float scores[10], *scores2;

public:
    Player()
    {
        scores2 = new float[10];
        id = 5;
    }
    Player(Player &p);
    void setid(int num)
    {
        id = num;
    }
    int getid()
    {
        return id;
    }
    operator int()
    {
        cout << "inside operator int conversion:";
        return id;
    }
    friend void set(Player *P);
    friend ostream &operator<<(ostream &out, Player *P);
};
Player::Player(Player &P)
{
    for (int i = 0; i < 5; i++)
    {
        *(this->scores2 + i) = *(P.scores2 + i); // deep copy
    }
    // this->scores2 = P.scores2; // shallow copy
}
ostream &operator<<(ostream &out, Player *P)
{
    out << "The scores are as follows:\n ";
    for (int i = 0; i < 5; i++)
    {
        out << "For Player number " << i << endl;
        for (int j = 0; j < 10; j++)
        {
            out << "the score number " << j << "is " << P[i].scores[j];
        }
    }
    return out;
}
void set(Player *P)
{
    float num;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the scores for the player " << i << endl;
        for (int j = 0; j < 10; j++)
        {
            cout << "Now enter the score number " << j << ": ";
            cin >> num;
            P[i].scores[j] = num;
        }
    }
}
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

    cout << int(p1); //      from class type to integer type (or any other type you wants)

    Player *p2 = new Player[5];
    for (int i = 0; i < 5; i++)
    {
        p2[i] = Player();
    }
    for (int j = 0; j < 5; j++)
    {
        p2[j].setid(10);
    }
    for (int k = 0; k < 5; k++)
    {
        cout << p2[k].getid();
    }
    Player *p3 = new Player[5];
    set(p3);
    cout << p3;
}