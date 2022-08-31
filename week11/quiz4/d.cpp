#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100];
vector<int> ans;

bool was[100000];

void dfs(int x){
    was[x]=true;
    for(int i=0;i<g[x].size();i++){
        if(!was[g[x][i]]){
            dfs(g[x][i]);
        }
    }
    ans.push_back(x);
}
int main(){
    int n,m; 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; 
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!was[i]){
            dfs(i);
        }
    }
    
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}