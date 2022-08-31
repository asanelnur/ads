#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n,m,x,y,l;
    cin>>n>>m;
    int a[n][n];

    int inf=INT_MAX/2;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>a[i][j];
    //         if(a[i][j]==0){
    //             a[i][j]=inf;
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=inf;
        }
        a[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y>>l;
        x--; y--;
        a[x][y]=l;
        a[y][x]=l;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]<inf && a[k][j]<inf){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==inf){
                a[i][j]=0;
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}