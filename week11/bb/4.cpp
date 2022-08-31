/*Graph - это набор вершин состаящий из пар G=(V,E), или 
набор объектов где это множества вершин это множества робер

BFS(queue),PFS(recursios or loop operator)
*/
#include <iostream>
using namespace std;
#define MXN 100
bool used[MXN];
int a[MXN][MXN];
int n;

void dfs(int v){
    used[v]=true;
    cout<<v<<" ";
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !used[i]){
            dfs(i);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dfs(0);
    // int cnt=0;
    // cout<<cnt;
    return 0;
}