#include<iostream>
using namespace std;


class smartPointr{
    int* ptr;
public:
    explicit smartPointr(int *p=NULL){
        ptr=p;
    }
    // Destructor
    ~smartPointr(){
        delete(ptr);
        }
    int& operator*(){
        return *ptr;
        }

};
int main(){
    smartPointr ptr(new int());
    *ptr=20;
    cout<<*ptr;

    return 0;



}
