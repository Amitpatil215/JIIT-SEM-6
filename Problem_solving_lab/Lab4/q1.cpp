#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector
    vector<int> v = {3, 2, 5, 1,-20};
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // set
    set<int> s = {2, 3, 1, 2, 5};

    for (auto element : s)
    {
        cout << element << " ";
    }
    cout << endl;
    // map
    map<int, string> m = {

        {2, "Two"},
        {3, "Three"},
        {1, "one"},
    };

    for (auto element : m)
    {
        cout << element.first << " " << element.second << endl;
    }
    cout << endl;

    // multi map
    multimap<int, string> mm;
    mm.insert({1, "hello"});
    mm.insert({1, "hi"});

    for (auto element : mm)
    {
        cout << element.first << " " << element.second << endl;
    }
    cout << endl;
}