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
/*
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
*/

class Abstract
{
public:
    virtual int GetArea(void) = 0;
    virtual void Draw(void) = 0;
};

class Line : public Abstract
{
protected:
    int x, y;

public:
    Line(int, int);
    void Draw(void);
    int GetArea(void);
};
Line::Line(int a, int b)
{
    x = a;
    y = b;
}
void Line::Draw(void)
{
    cout << "\n Line Drawing code";
}
int Line::GetArea(void)
{
    cout << "\nLine Area ";
}
///////////////////////////
class Circle : public Line
{
protected:
    int radius;

public:
    Circle(int, int, int);
    void Draw(void);
    int GetArea(void);
};
Circle::Circle(int a, int b, int c) : Line(a, b)
{
    radius = c;
}
void Circle::Draw(void)
{
    cout << "\nCircle drawing code";
}
int Circle::GetArea(void)
{
    cout << "\nCircle area code";
}
//////////////////////////////
class Rectangle : public Line
{
protected:
    int Width, Height;

public:
    Rectangle(int, int, int, int);
    void Draw(void);
    int GetArea(void);
};
Rectangle::Rectangle(int a, int b, int c, int d) : Line(a, b)
{
    Width = c;
    Height = d;
}
void Rectangle::Draw(void)
{
    cout << "\nRectangle drawing code";
}
int Rectangle::GetArea(void)
{
    cout << "\nRectangle area code";
}
///////////////////////////////
class Cylinder : public Line
{
protected:
    int Width, Height;

public:
    Cylinder(int, int, int, int);
    void Draw(void);
    int GetArea(void);
};
Cylinder::Cylinder(int a, int b, int c, int d) : Line(a, b)
{
    Width = c;
    Height = d;
}
void Cylinder::Draw(void)
{
    cout << "\nCylinder Drawing Code";
}
int Cylinder::GetArea(void)
{
    cout << "\nCylider Area code";
}
////////////////////////////////
class Triangle : public Line
{
protected:
    int Width, Height;

public:
    Triangle(int, int, int, int);
    void Draw(void);
    int GetArea(void);
};
Triangle::Triangle(int a, int b, int c, int d) : Line(a, b)
{
    Width = c;
    Height = d;
}
void Triangle::Draw(void)
{
    cout << "\nTriangle Drawing Code";
}
int Triangle::GetArea(void)
{
    cout << "\nTriangle area code";
}
int main(void)
{
    /*
    Triangle t1(3, 4, 5, 19);
    Circle c1(3, 4, 5);
    Rectangle r1(3, 4, 10, 20);
    Cylinder c2(3, 4, 5, 10);

    t1.Draw();
    cout << "The area is " << t1.GetArea();
    cout << "\n///////////\n";
    c1.Draw();
    cout << "The area is " << c1.GetArea();
    cout << "\n///////////\n";
    r1.Draw();
    cout << "The area is " << r1.GetArea();
    cout << "\n///////////\n";
    c2.Draw();
    cout << "The area is " << c2.GetArea();
    */

    // The above process can also be done through array of the pointers of the base class (ERROR)
    Line *p[4];
    // cout << p->GetArea() << endl;
    // p[0] = &t1;

    p[0] = new Triangle(3, 4, 5, 19);
    // cout << p[0]->GetArea() << endl;
    p[1] = new Circle(3, 4, 5);
    // cout << p[1]->GetArea() << endl;
    p[2] = new Rectangle(3, 4, 10, 20);
    // cout << p[2]->GetArea() << endl;
    p[3] = new Cylinder(3, 4, 5, 10);
    // scout << p[3]->GetArea() << endl;

    for (int i = 0; i < 4; i++)
    {
        p[i]->Draw();
        cout << "\nThe Area is " << p[i]->GetArea() << endl;
    }

    return 0;
}