#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1000000];
vector<int> ans;

bool was[1000000];
void dfs(int x){
    was[x]=true;
    for(int i=0;i<g[x].size();i++){
        if(!was[g[x][i]]){
            dfs(g[x][i]);
        }
    }
    ans.push_back(x);
}
void f(){
    cout<<"NO";
}
int main(){
    int n,m; 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; 
        cin>>u>>v;
        g[u].push_back(v);
    }
    f();
    return 0;
}