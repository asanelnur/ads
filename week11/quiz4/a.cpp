#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100001];
vector<int> res[100000];
bool was[100000];
int k=0;

void dfs(int x){
    was[x]=true;
    res[k].push_back(x);
    for(int i=0;i<g[x].size();i++){
        if(!was[g[x][i]]){
            dfs(g[x][i]);
        }
    }
}
int main(){
    int n,m; 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!was[i]){
            dfs(i);
            k++;
        }
    }
    int mini=res[0].size();
    for(int i=0;i<k;i++){
        if(res[i].size()<mini) mini=res[i].size();
    }
    cout<<mini;
    return 0;
}