#include <iostream>
#include <vector>
const int MAX_INT=1e7;
using namespace std;

vector<int> d(100,MAX_INT);
int n,m,x,y,l;
int g[100][100];
bool used[100];
int c[100];


int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>l;
        x--; y--;
        g[x][y]=l;
        g[y][x]=l;
    }
    int rr,mer,ph,gr;
    rr--; mer--; ph--; gr--;
    cin>>rr>>mer>>ph>>gr;
    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++){
            if(!used[j] && (v==-1 || d[v]>d[j])){
                v=j;
            }
        }
        used[v]=true;
        for(int j=0;j<n;j++){
            if(j==gr) break;
            if(!used[j] && g[v][j] && d[j]>g[v][j]){
                d[j]=g[v][j];
                g[v][j]=-1;
                c[j]=v;
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=g[i][c[i]];
    }
    cout<<ans;
    return 0;
}