#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int k[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>k[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        int minelof_j=k[i][0];
        int in_minelof_j=0;
        int yj=1;
        for(int j=1;j<m;j++){
            if(minelof_j>k[i][j]){
                minelof_j=k[i][j];
                in_minelof_j=j;
            }else if(minelof_j==k[i][j]){
                yj++;
            }
        }
        int maxelof_i=k[i][in_minelof_j];
        int yi=1;
        for(int i=0;i<n;i++){
            if(maxelof_i<k[i][in_minelof_j]){
                maxelof_i=k[i][in_minelof_j];
            }else if(maxelof_i==k[i][in_minelof_j]){
                yi++;
            }
        }
        if(maxelof_i==minelof_j) cnt+=min(yi,yj);
    }
    cout<<cnt;
    return 0;
}

//1 2 3
//6 5 4
//7 8 9 