#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Regex Match
    if (regex_match(("softwareTesting"), regex("(soft)(.*)")))
    {
        cout << "matched" << endl;
    }
    else
    {
        cout << "Not Matched" << endl;
    }

    //* regex search
    // string to be searched
    string mystr = "She sells_sea shells in the sea shore";

    // regex expression for pattern to be searched
    regex regexp("s[a-z_]+");

    // flag type for determining the matching behavior (in this case on string objects)
    smatch m;

    // regex_search that searches pattern regexp in the string mystr
    regex_search(mystr, m, regexp);

    cout << "String that matches the pattern:" << endl;
    for (auto x : m)
        cout << x << " ";

    //* regex match
    string mystr1 = "This is software testing Help portal \n";

    cout << "Input string: " << mystr1 << endl;

    // regex to match string beginning with 'p'
    regex regexp1("p[a-zA-z]+");
    cout << "Replace the word 'portal' with word 'website' : ";
    // regex_replace() for replacing the match with the word 'website'
    cout << regex_replace(mystr1, regexp1, "website");

    string result;

    cout << "Replace the word 'website' back to 'portal': ";
    // regex_replace( ) for replacing the match back with 'portal'
    regex_replace(back_inserter(result), mystr1.begin(), mystr1.end(),
                  regexp1, "portal");

    cout << result;
}