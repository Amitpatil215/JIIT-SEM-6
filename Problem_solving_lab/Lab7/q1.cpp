#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

ostream &form(ostream &output)
{
    output.setf(ios::showpos);
    output.setf(ios::showpoint);
    output.fill('*');
    output.precision(2);
    output << setiosflags(ios::fixed) << setw(10);

    return output;
}

int main()
{
    cout << form << 7864.5;

    getch();
    return 0;
}
