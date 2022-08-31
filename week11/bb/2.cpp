#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

bool used[MAXN];
int a[MAXN][MAXN];
int n;

void dfs(int v){
    cout<<v+1<<" ";
    used[v]=true;
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !used[i]){
            dfs(i);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs(i);
            cout<<endl;
        }
    }
    return 0;
}