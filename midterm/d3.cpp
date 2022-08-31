#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
            cout<<-1<<endl;
        }
        else{
            bool ans=false;
            if(y%2==0){
                int l=0;
                int r=k-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(b[y][m]==x){cout<<y<<" "<<m<<endl;ans=true;break;}
                    if(b[y][m]>x) l=m+1;
                    else r=m-1;
                }
            }else{
                int l=0;
                int r=k-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(b[y][m]==x){cout<<y<<" "<<m<<endl;ans=true;break;}
                    if(b[y][m]<x) l=m+1;
                    else r=m-1;
                }
            }
            if(!ans) cout<<-1<<endl;
        }
    }
    return 0;
}