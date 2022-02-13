#include <iostream>
#include <string>

using namespace std;

void insertFn(string str1, string str2)
{

    str1.insert(2, str2);
    cout << str1;
}

// Driver code
int main()
{
    string str1("amit");
    string str2("ok");
    insertFn(str1, str2);

    return 0;
}