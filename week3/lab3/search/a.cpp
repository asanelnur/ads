#include <iostream>
using namespace std;
int main(){
    int n; 
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    int k; 
    cin>>k;
    for(int i=1;i<=n;i++){
        if(arr[i]==k){
            cout<<i<<" "; 
        }
    }
    return 0;
}