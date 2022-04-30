

#include <iostream>
#include <regex>
using namespace std;

bool isValid(string s)
{

    const regex pattern("(0|91)?[7-9][0-9]{9}");

    if (regex_match(s, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "347873923408";
    if (isValid(s))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }
    return 0;
}
