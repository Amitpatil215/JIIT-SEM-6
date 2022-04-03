
#include <iostream>
#include<string>
using namespace std;
class person{
public:
    int age;
    string name;

    person(int a,string n){
        a=age;
        name=n;
    }

    person* getDetails(){
    return this;
    }
};
int main(){
    person amit(21,"Amit");
    person *a=amit.getDetails();
    cout<<a->age<<" "<<a->name;


}
