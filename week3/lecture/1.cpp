//linear search
#include <iostream>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>x;
        a[i]=x;
    }
    int k;
    cin>>k;
    for(int i=0;i<n;i++){
        if(a[i]==k){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}