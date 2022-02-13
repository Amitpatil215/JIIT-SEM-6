#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
    double l, w;

public:
    void setLength(double len)
    {
        l = len;
    }
    void setWindth(double width)
    {
        w = width;
    }
    float perimeter()
    {
        return 2 * (l + w);
    }
    float area()
    {
        return l * w;
    }
    void show()
    {
        cout << "len " << l << " width " << w << endl;
    }
    int sameArea(Rectangle r)
    {
        if (r.area() == area())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    Rectangle r1, r2;
    r1.setLength(5);
    r1.setWindth(2.5);
    r2.setLength(5);
    r2.setWindth(18.9);

    cout << " R1 "
         << " area " << r1.area() << " Perimerter " << r1.perimeter() << endl;

    cout << " R2 "
         << " area " << r2.area() << " Perimerter " << r2.perimeter() << endl;

    // Que iii here

    cout << "same area " << r1.sameArea(r2) << endl;
    r1.setLength(5);
    r1.setWindth(18.9);
    cout << "same area " << r1.sameArea(r2) << endl;
}