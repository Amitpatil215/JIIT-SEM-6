#include <iostream>
#include <exception>
using namespace std;

class A
{
public:
    A()
    {
    }
    class B
    {
    };
    class C : public virtual B
    {
    };
    class D : public virtual B
    {
    };
    void getData()
    {
        throw D();
    }
};
int main()
{

    A a1;
    try
    {
        a1.getData();
    }
    catch (A ::B &)
    {
        cout << "In class A";
    }
    catch (A ::C &)
    {
        cout << "In class B";
    }
    catch (A ::C &)
    {
        cout << "In class C";
    }
    catch (...)
    {
        cout << "None";
    }
}
