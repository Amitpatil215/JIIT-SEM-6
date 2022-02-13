#include <bits/stdc++.h>

using namespace std;
struct fraction
{
    int z;
    int n;
};
int main()
{
    fraction f1;
    fraction f2;
    f1.z = 10;
    f1.n = 5;

    f2.z = 4;
    f2.n = 1;
    double f1val = f1.z / f1.n;
    double f2val = f2.z / f2.n;

    if (f1val > f2val)
    {
        cout << 1;
    }
    else if (f1val < f2val)
    {
        cout << -1;
    }
    else
    {
        cout << 0;
    }
}