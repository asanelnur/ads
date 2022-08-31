#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int a[n][m];
    int d[n][m];
    queue<pair<int,int> > q;
    int mushroom = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=n*m;
            cin>>a[i][j];
            if(a[i][j]==2){
                q.push({i,j});
                d[i][j]=0;
            }else if(a[i][j]==1){
                mushroom++;
            }
        }
    }
    if(mushroom==0){
        cout<<0<<endl;
        return 0;
    }

    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        if(p.first!=0){
            if(a[p.first-1][p.second]==1){
                a[p.first-1][p.second]=2;
                mushroom--;
                d[p.first-1][p.second]=d[p.first][p.second]+1;
                q.push({p.first-1,p.second});
            }
        }
        if(p.first!=n-1){
            if(a[p.first+1][p.second]==1){
                a[p.first+1][p.second]=2;
                mushroom--;
                d[p.first+1][p.second]=d[p.first][p.second]+1;
                q.push({p.first+1,p.second});
            }
        }
        if(p.second!=0){
            if(a[p.first][p.second-1]==1){
                a[p.first][p.second-1]=2;
                mushroom--;
                d[p.first][p.second-1]=d[p.first][p.second]+1;
                q.push({p.first,p.second-1});
            }
        }
        if(p.second!=n-1){
            if(a[p.first][p.second+1]==1){
                a[p.first][p.second+1]=2;
                mushroom--;
                d[p.first][p.second+1]=d[p.first][p.second]+1;
                q.push({p.first,p.second+1});
            }
        }
    }
    if(mushroom!=0){
        cout<<-1;
        return 0;
    }

    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==2 && d[i][j]>maxi) maxi=d[i][j];
        }
    }
    cout<<maxi;
    return 0;
}