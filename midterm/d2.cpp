#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m,k;
    cin>>m>>k;
    int b[m][k];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>b[i][j];

        }
    }
    for(int i=0;i<n;i++){
        int y=0;
        while(a[i]<b[y][0] && a[i]<b[y][k-1]){
            y++;
        }
        if(y==m){
            cout<<-1<<endl;
        }
        else{
            bool ans=false;
            for(int j=0;j<k;j++){
                if(b[y][j]==a[i]){
                    ans=true;
                    cout<<y<<" "<<j<<endl;
                    break;
                }
            }
            if(!ans) cout<<-1<<endl;
        }
    }
    return 0;
}