#include <iostream>
#include <exception>
using namespace std;
int main()
{
    int x = 10, y = 20, z = 30;
    float d;
    try
    {
        if ((x - y) != 0)
        {
            d = z / (x - y);
            cout << d;
        }
        else
        {
            throw(x - y);
        }
    }
    catch (int m)
    {
        cout << "Infinite " << m;
    }
}
