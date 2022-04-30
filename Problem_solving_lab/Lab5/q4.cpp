#include <iostream>
#include <regex>
#include <string>
using namespace std;

void PrintMatches2(string str, regex reg)
{
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while (currentMatch != lastMatch)
    {
        smatch match = *currentMatch;
        cout << match.str() << endl;
        currentMatch++;
    }
    cout << endl;
}

int main()
{
    string str = "This ape was at the apex";
    regex reg("(ape[^ ]?)");
    PrintMatches2(str, reg);

    string str1 = "I picked the pickle";
    regex reg1("(pick[^ ]+?)");
    PrintMatches2(str1, reg1);
}