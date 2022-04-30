// C++ program to count words in
// a string using stringstream.
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int countWords(string str)
{
    // Breaking input into word
    // using string stream

    // Used for breaking words
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

// Driver code
int main()
{
    string s = "work while you work play while you";
    cout << " Number of words are: " << countWords(s);
    return 0;
}
