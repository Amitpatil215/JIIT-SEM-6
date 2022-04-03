
#include <iostream>

using namespace std;

int main(){
int arr[6]={0};

int ballet[]={1,2,3,4,5,6,1,2};
int spoiltBallot=0;

for(int i:ballet){

    if(i>5){
        spoiltBallot++;
    }else{
        arr[i]++;
    }
}
for(int i=1;i<=5;i++){
    cout<<i<<" ";
    cout<<arr[i]<<endl;
}
cout<<"spoilet Ballot"<<spoiltBallot<<endl;

}
