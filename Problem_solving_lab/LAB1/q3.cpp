#include <bits/stdc++.h>
using namespace std;

int tripleByValue(int n)
{
    return n * 3;
}
void tripleByRef(int &n)
{
    n = n * 3;
}
int main()
{
    int n = 10;
    cout << tripleByValue(n) << endl;
    tripleByRef(n);
    cout << n << endl;
}