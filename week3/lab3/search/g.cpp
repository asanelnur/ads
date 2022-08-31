#include <iostream>
using namespace std;
bool bs(int arr[],int l,int r,int x){
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==x) return true;
        else if(arr[m]>x) r=m-1;
        else l=m+1;
    }
    return false;
}
int main(){
    int n,k; cin>>n>>k; int a[n],b[k];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        if(bs(a,0,n-1,b[i])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}