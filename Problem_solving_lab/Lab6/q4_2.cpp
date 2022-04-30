#include <iostream>
#include <exception>
using namespace std;

class B
{
};
class D : public B
{
};
int main()
{
    D d;
    try
    {
        throw d;
    }
    catch (B b)
    {
        cout << "Base Exception";
    }
    catch (Derived d)
    {
        cout << "Derived Exception";
    }
    return 0;
}
