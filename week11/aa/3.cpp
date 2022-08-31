#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,x,y,v;
int used[100];
int d[100];
vector<int> g[100];

void bfs(int v){
    queue<int> q;
    used[v]=1;
    q.push(v);
    d[v]=0;
    while(!q.empty()){
        int x = q.front();
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            if(used[y]==0){
                q.push(y);
                used[y]=1;
                d[y]=d[x]+1;
            }
        }
        q.pop();
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
    bfs(v-1);
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}