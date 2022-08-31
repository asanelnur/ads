#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cnt=0;
vector<int> g[1000000];
vector<int> ans;
vector<int> g2[1000000];

bool was[1000000];
bool used[1000000];

void dfs(int x){
    was[x]=true;
    for(int i=0;i<g[x].size();i++){
        if(!was[g[x][i]]){
            dfs(g[x][i]);
        }
    }
    ans.push_back(x);
}
void dfs_d(int v){
    used[v]=true;
    for(int i=0;i<g2[v].size();i++){
        if(!used[g2[v][i]]){
            dfs_d(g2[v][i]);
        }
    }
}
int main(){
    int n,m; 
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; 
        cin>>u>>v;
        g[u].push_back(v);
        g2[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!was[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        if(!used[i]){
            dfs_d(ans[i]);
            cnt++;
        }
    }
    if(cnt!=ans.size()){
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}