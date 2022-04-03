#include<iostream>
#include<vector>
using namespace std;

int fun1(){
return 2;
}
int main(){
cout<<"use of auto";
vector<char> arr;
arr.push_back('a');
for(auto ch :arr){
    cout<<typeid(c).name()<<endl;
}
decltype(fun1()) x;
  cout << typeid(x).name() << endl;
}

