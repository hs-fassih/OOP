#include <iostream>
using namespace std;
class Animal
{
private:
    int id;
    char *name, *description;

public:
    void setid(int ID);
    int getid();
    void setname(char *Name);
    char *getname();
    void setdescription(char *Description);
    char *getdescription();
    Animal(char *Name = NULL, char *Description = NULL, int ID = 0);
    Animal(Animal &copy);
    /*
    void search(string n, Animal arr[])
    {
    }
    */
    void Printanimal(Animal arr[], int size)
    {
        cout << "\nThe list of animals is as follows:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "\nName:\t" << arr[i].getname() << "\tID:\t" << arr[i].getid() << "\tDescription\t" << arr[i].getdescription();
        }
    }
};
void Animal::setid(int ID)
{
    id = ID;
    cout << id;
}
int Animal::getid()
{
    return id;
}
void Animal::setname(char *Name)
{
    int i = 0;
    while (*(Name + i) != '\0')
    {
        *(name + i) = *(Name + i);
        i++;
    }
    // cout << "..............";
}
char *Animal::getname()
{
    return name;
}
void Animal::setdescription(char *Description)
{
    int j = 0;
    while (*(Description + j) != '\0')
    {
        *(description + j) = *(Description + j);
        j++;
    }
}
char *Animal::getdescription()
{
    return description;
}
Animal::Animal(char *Name, char *Description, int ID)
{
    id = ID;
    name = Name;
    description = Description;
}
Animal::Animal(Animal &copy)
{
    this->id = copy.id;
    this->name = copy.name;
    this->description = copy.description;
}
int main()
{
    int ID;
    char Name[20], Description[40], *D;
    Animal *animal = new Animal[5]; // size should be 20
    for (int i = 0; i < 5; i++)
    {
        if (i != 0)
            cin.ignore();
        cout << "\nEnter the name and description of the animal\n";
        cin.getline(Name, 20);
        Name[i] = '\0';
        animal[i].setname(Name);
        // cin >> ID;           Auto ID
        animal[i].setid(i + 1);
        // cin.ignore();
        cin.getline(Description, 40);
        Description[i] = '\0';
        animal[i].setdescription(Description);
    }
    Animal A1;
    A1.Printanimal(animal, 5);
    /*
    Animal A1(animal[0]);
    cout << "\nEnter the name of animal being searched: ";
    cin.getline(Name, 20);
    A1.search(Name, animal);
    */
}