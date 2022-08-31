#include <iostream>
using namespace std;
int greatest_divisible(int a,int b){
    while(a%b==0){
        a/=b;
    }
    return a;
}
bool isugly(int number){
    number=greatest_divisible(number,2);
    number=greatest_divisible(number,3);
    number=greatest_divisible(number,5);
    return (number==1) ? true : false;
}
int main(){
    int n,cnt=1,i=1;
    cin>>n;
    while(n>cnt){
        i++;
        if(isugly(i)){
            cnt++;
        }
    }
    cout<<i<<endl;
    return 0;
}