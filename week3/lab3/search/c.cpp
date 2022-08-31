#include <iostream>
using namespace std;
int main(){
    int n,x; cin>>n; int arr[n];
    for(int i=1;i<=n;i++){  
        cin>>x;
        arr[i]=x;
    }
    int max=arr[1];
    int max_index=1;
    for(int i=2;i<=n;i++){
        if(arr[i]>max){
            max=arr[i];
            max_index=i;
        }
    }
    cout<<max_index;
    return 0;
}