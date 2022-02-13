#include <bits/stdc++.h>
using namespace std;
void *operator new(size_t size)
{
    cout << "Overloading new operator";
    void *p = ::operator new(size);
    return p;
}

void operator delete(void *p)
{
    cout << "Overloading delete";
    free(p);
}

class Person
{
private:
    string name;

public:
    friend ostream &operator<<(ostream &output, const Person &p)
    {
        output << "Person's Name is " << p.name;
        return output;
    }
    friend istream &operator>>(istream &input, Person &p)
    {
        input >> p.name;
        return input;
    }
};

int main()
{
    Person p;
    cin >> p;
    cout << p;
}