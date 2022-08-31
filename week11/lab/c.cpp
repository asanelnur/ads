#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005

using namespace std;

int n;
bool used[MAXN];
vector<int> comp;
vector<int> g[MAXN];

void dfs(int v){
    used[v]=true;
    comp.push_back(v);
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]])
        dfs(g[v][i]);
    }
}

int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<int> > vec;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i);
            vec.push_back(comp);
            comp.clear();
        }
    }
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++){
        vector<int> v=vec[i];
        cout<<v.size()<<endl;
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}