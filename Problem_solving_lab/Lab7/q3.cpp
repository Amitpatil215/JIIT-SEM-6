

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countWords(string str)
{

    stringstream s(str);

    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

int main()
{
    string s = "work while you work play while you";
    cout << " Number of words are: " << countWords(s);
    return 0;
}
