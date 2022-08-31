#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans(int arr[],int l,int r,int x){
    while(l<=r){
        int m=l+(r-l)/2;
        //cout<<l<<" "<<r<<endl;
        if(arr[m]==x) return m;
        if(arr[m]<x) l=m+1;
        else r=m-1;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m,k;
    cin>>m>>k;
    int b[m][k];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int x=a[i];
        int y=0;
        while(x<b[y][0] && x<b[y][k-1]){
            y++;
        }
        if(y==m){
            cout<<-1;
            continue;
        }else{
            bool ans=false;
            for(int j=0;j<k;j++){
                if(b[y][j]==x){
                    cout<<y<<" "<<j<<endl;
                    ans=true;
                    break;
                }
            }
            if(!ans) cout<<-1<<endl;
        }
    }
    return 0;
}