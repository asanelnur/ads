#include <iostream>
using namespace std;
bool prime(int n){
    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
void ans(int n){
    if(prime(n)) cout<<"prime";
    else cout<<"composite";
}
int main(){
    int n;
    cin>>n;
    ans(n);
    return 0;
}