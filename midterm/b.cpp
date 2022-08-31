#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long minsum(int arr[],int n) {
    sort(arr,arr+n);
    vector<int> curr;
    int i = 0;
    int j = 0;
    long long ans = 0;
    while(n - i + curr.size() - j > 1) {
        long long n1, n2;
        if(i < n && j < curr.size()){
            if(arr[i] <= curr[j]) n1= arr[i++];
            else n1= curr[j++];
        }
        else if(i < n) n1= arr[i++];
        else if(j < curr.size()) n1= curr[j++];
        if(i < n && j < curr.size()) {
            if(arr[i] <= curr[j]) n2 = arr[i++];
            else n2 = curr[j++];
        }
        else if(i < n) n2 = arr[i++];
        else if(j < curr.size()) n2 = curr[j++];
        long long sum = n1 + n2;
        curr.push_back(sum);
        ans += sum;
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<minsum(a,n);
    return 0;
}