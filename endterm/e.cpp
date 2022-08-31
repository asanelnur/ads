#include <bits/stdc++.h>
using namespace std;

int a[123456];
vector<int> sosedy[123456], p;
int c,n,m;

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
    for (int t : sosedy[x]) {
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

void doit() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        sosedy[u].push_back(v);
        sosedy[v].push_back(u);   
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
}
int main() {    
    doit();
    return 0;
}