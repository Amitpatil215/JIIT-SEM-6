#include <bits/stdc++.h>
using namespace std;

class ZooAnimal
{

public:
    int cageNumber;
    int weightDate;
    int weight;
    char *str;
    ZooAnimal(char str[], int cg, int wd, int w)
    {
        this->str = new char[20];
        strcpy(this->str, str);

        cageNumber = cg;
        weightDate = wd;
        weight = w;
    }
};

int main()
{
}