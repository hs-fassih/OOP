#include <iostream>
using namespace std;
class Continent
{
public:
    void mainfunction()
    {
        cout << "This is the Continent of Asia which";
    }
};
class Country : public Continent
{
public:
    void mainfunction()
    {
        cout << " contains the Country of Pakistan";
    }
};
class Province : public Country
{
public:
    void mainfunction()
    {
        cout << " and the Province of Punjab";
    }
};
int main()
{
    Continent Asia;
    Country Pakistan;
    Province Punjab;
    Asia.mainfunction();
    Pakistan.mainfunction();
    Punjab.mainfunction();
    return 0;
}