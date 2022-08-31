#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100

using namespace std;

int n;
bool used[MAXN];
vector<int> ans(MAXN);
vector<int> g[MAXN];

void topsort(int v){
    used[v]=true;
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]])
        topsort(g[v][i]);
    }
    ans.push_back(v+1);
}

int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==0 && y==0) break;
        x--; y--;
        g[x].push_back(y);
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            topsort(i);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}