//binary search 
#include <iostream>
using namespace std;
int ans(int arr[],int l,int r,int x){
    //int m=(l+r)/2;
    while(l<=r){
        int m=l+(r-l)/2;
        //cout<<l<<" "<<r<<endl;
        if(arr[m]==x) return m;
        if(arr[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}
int ans2(int arr[],int l,int r,int x){
    if(l>r) return -1;
    int m=l+(r-l)/2;
    if(arr[m]==x) return m;
    if(arr[m]<x) return ans2(arr,m+1,r,x);
    return ans2(arr,l,m-1,x);
}
int main(){
    int arr[]={2,3,4,10,20,30,45,89,124,178,200,212,245,269,300,321,400};
    int x;
    cin>>x;
    int n=sizeof(arr)/sizeof(int);
    cout<<x<<" : "<<ans(arr,0,n-1,x);
    return 0;
}