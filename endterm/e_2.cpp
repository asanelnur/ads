#include <iostream>
#include <vector>
using namespace std;

int a[10000];
vector<int> graph[10000];
vector<int> p;
int c=0,n,m;

int g(int x) {
    if (x == a[x]) return x;
    else {
        a[x] = g(a[x]);
        return a[x];
    }
}

void sol(int x) {
     p.push_back(c);
     c += 1;
    for (int i=0;i<graph[x].size();i++){
        int t=graph[x][i];
        if (t >= x) {
            int f = g(t);
            int s = g(x);
            if (f != s) {
                c--;
                a[f] = s;
            }
        }
    }
}
int main() {    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);   
    }

    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    for(int i = n; i > 0; i--){
        sol(i);
    }

    for(int i = p.size() - 1; i >= 0; i--){
        cout << p[i] << "\n";
    }
    return 0;
}