#include <iostream>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        int x,y,z; cin>>x>>y>>z;
        if(a[x-1][y-1]==1 && a[y-1][z-1]==1 && a[z-1][x-1]==1){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}