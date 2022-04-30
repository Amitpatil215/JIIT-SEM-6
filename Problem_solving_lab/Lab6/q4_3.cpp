#include <iostream>
#include <exception>
using namespace std;
class T
{
    static int c;
    int i;

public:
    T()
    {
        c++;
        i = c;
        cout << "Creating object " << i;
        if (i == 4)
            throw 4;
    }
    ~T() { cout << "Deleting object " << i; }
};
int T::c = 0;
int main()
{
    try
    {
        T a[5];
    }
    catch (int id)
    {
        cout << "Caught " << id;
    }
}
