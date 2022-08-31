#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,x,y;
int used[100];
vector<int> g[100];

void bfs(int v){
    queue<int> q;
    used[v]=1;
    q.push(v);
    while(!q.empty()){
        int x = q.front();
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            if(used[y]==0){
                q.push(y);
                used[y]=1;
            }
        }
        q.pop();
    }
}
int main(){

    return 0;
}