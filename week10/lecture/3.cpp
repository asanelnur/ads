/*Graph - это набор вершин состаящий из пар G=(V,E), или 
набор объектов где это множества вершин это множества робер

BFS(queue),PFS(recursios or loop operator)

(0)->(1)
        \
        (2)
   0 1 2
0  0 1 0
1  0 0 1
2  0 0 0
*/
#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}