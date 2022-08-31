#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    string ans="";
    long long p[n];
    p[0]=1;
    for(int i=1;i<n;i++){
        p[i]=p[i-1]*2;
    }
    for(int i=0;i<n;i++){
        long long c=h[i];
        if(i>0){
            c-=h[i-1];
        }
        c/=p[i];
        c+=97;
        cout<<char(c);
    }
    return 0;
}