#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,x,y,v;
int used[100];
int d[100];
vector<int> g[100];

void dfs(int v){
    cout<<v+1<<" ";
    used[v]=1;
    for(int i=0;i<g[v].size();i++){
        int y=g[v][i];
        if(used[y]==0){
            dfs(y);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cin>>v;
    dfs(v-1);
    return 0;
}