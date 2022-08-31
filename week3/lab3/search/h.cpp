#include <iostream>
using namespace std;
int bs(int l,int r,int cnt){
    while(l<=r){
        if(l==r) return cnt;
        int m=l+(r-l)/2;
        r=m;
        cnt++;
    }
    return cnt;
}
int main(){
    int n; cin>>n;
    cout<<bs(0,n-1,0);
    return 0;
}