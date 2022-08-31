#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100

using namespace std;

vector<int> ans;
bool used[MAXN];
int a[MAXN][MAXN];
int n;
void dfs(int v){
    used[v]=true;
    cout<<v+1<<" ";
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !used[i]){
            dfs(i);
        }
    }
}

int main(){
    int m,x,y;
    cin>>n>>m;
    while(cin>>x>>y && (x!=0 && y!=0) && m>0){
        x--; y--;
        a[x][y]=1;
        m--;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs(i);
        }
    }
    return 0;
}