//topsort
#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100

using namespace std;

vector<int> ans;
bool used[MAXN];
int a[MAXN][MAXN];
int n;
void dfs(int v){
    used[v]=true;
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !used[i]){
            dfs(i);
        }
    }
    ans.push_back(v+1);
}

void dfs1(int v){
    used[v]=true;
    for(int i=0;i<n;i++){
        if(a[v][i]==1 && !used[i]){
            dfs(i);
        }
    }
    ans.push_back(v+1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}