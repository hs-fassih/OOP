#include <iostream>
using namespace std;
class Player
{
private:
    char *name;
    int age;
    int size;
    int score;

public:
    Player(int age = 0, int size = 0, int score = 0, char *name = NULL);
    void operator++();    // pre-increment
    void operator++(int); // post-increment
    void operator--();    // pre-decriment
    void operator--(int); // post-decriment
    void operator+(Player &p);
    void operator-(Player &p); // should '&' be used before the operator name?
    void operator=(Player &p); // this operator is not necessary as it is done automatically
    bool operator>(Player &p);
    bool operator<(Player &p);
    bool operator==(Player &p);
    char operator[](int i);
    Player &operator*(Player &p);
    Player &operator%(Player &p);
    Player &operator/(Player &p);
    Player &operator&(Player &p); // how to use this operator
    void *operatornew(size_t);
    friend ostream &operator<<(ostream &output, Player &p);
    friend istream &operator>>(istream &input, Player &p);
};
Player::Player(int age, int size, int score, char *name)
{
    this->name = name;
    this->age = age;
    this->size = size;
    this->score = score;
}
void Player::operator++() // no argument for pre increment
{
    this->age++;
    this->size++;
    this->score++;
}
void Player::operator++(int) // int is a must argument in post increment
{
    ++this->age;
    ++this->size;
    ++this->score;
}
void Player::operator--() // no argument for pre increment
{
    this->age--;
    this->size--;
    this->score--;
}
void Player::operator--(int) // int is a must argument in post decrement
{
    --this->age;
    --this->size;
    --this->score;
}
void Player::operator+(Player &p)
{
    this->age = this->age + p.age;
    this->size = this->size + p.size;
    this->score = this->score + p.score;
}
void Player::operator-(Player &p)
{
    this->age = this->age - p.age;
    this->size = this->size - p.size;
    this->score = this->score - p.score;
}
void Player::operator=(Player &p)
{
    this->age = p.age;
    this->size = p.size;
    this->score = p.score;
}
bool Player::operator>(Player &p)
{
    if (this->score > p.score)
    {
        return 1;
    }
    return 0;
}
bool Player::operator<(Player &p)
{
    if (this->score < p.score)
    {
        return 1;
    }
    return 0;
}
bool Player::operator==(Player &p)
{
    if (this->score == p.score)
    {
        return 1;
    }
    return 0;
}
char Player::operator[](int i)
{
    if (i >= 0 && i < size)
        return name[i];
}
Player &Player::operator*(Player &p)
{
    Player temp;
    temp.age = this->age * p.age;
    temp.size = this->size * p.size;
    temp.score = this->score * p.score;
    return temp;
}
Player &Player::operator%(Player &p)
{
    Player temp;
    temp.age = this->age % p.age;
    temp.size = this->size % p.size;
    temp.score = this->score % p.score;
    return temp;
}
Player &Player::operator/(Player &p)
{
    Player temp;
    temp.age = this->age / p.age;
    temp.size = this->size / p.size;
    temp.score = this->score / p.score;
    return temp;
}
Player &Player::operator&(Player &p)
{
    Player temp;
    temp.age = this->age & p.age;
    temp.size = this->size & p.size;
    temp.score = this->score & p.score;
    return temp;
}
void *operatornew(size_t siz)
{
    void *ptr = ::operatornew(siz);
    return ptr;
}
/*                                           //these can also be operated as friends
ostream &operator<<(ostream &output, Player &p)
{
    output << "name is: " << p.name << endl;
    output << "age is: " << p.age << endl;
    output << "size is: " << p.size << endl;
    output << "Score is: " << p.score << endl;
    return output;
}
istream &operator>>(istream &input, Player &p)
{
    cout << "Enter Age: ";
    input >> p.age;
    cout << "Enter Size: ";
    input >> p.size;
    return input;
}
*/
ostream &operator<<(ostream &output, Player &p)
{
    output << "name is: " << p.name << endl;
    output << "age is: " << p.age << endl;
    output << "size is: " << p.size << endl;
    output << "Score is: " << p.score << endl;
    return output;
}
istream &operator>>(istream &input, Player &p)
{
    cout << "Enter Age: ";
    input >> p.age;
    cout << "Enter Size: ";
    input >> p.size;
    return input;
}
int main()
{
    char n[20] = {'S', 'y', 'e', 'd', ' ', 'F', 'a', 's', 's', 'i', 'h'};
    Player p1(5, 10, 15, n), p2(7, 14, 21, n), p3(9, 18, 27, n), p4;
    Player *ptr = new Player(7, 14, 21, n);
    // ptr->operator<<
    /*
    ++p1; // no argument for pre increment
    p2++; // int is a must argument in post increment
    cout << p1 << p2;

    int condition=(p1>p2);
    cout<<(p1==p2);

    Player p5 = p1 * p2;
    cout << p5;

    cout << (p1 % p2);

    Player p3(5, 3);
    Player p4(10, 2);
    cin >> p3 >> p4;
    cout << p3 << p4;

    char ch;
    ch = p1[2];
    cout << ch;
    */
}