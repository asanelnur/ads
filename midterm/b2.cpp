#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void minsum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<int> curr;
    int i = 0;
    int j = 0;
    long long cost = 0;
    while(arr.size() - i + curr.size() - j > 1) {
        long long num1, num2;
        if(i < arr.size() && j < curr.size()) {
            if(arr[i] <= curr[j]) num1 = arr[i++];
            else num1 = curr[j++];
        }
        else if(i < arr.size()) num1 = arr[i++];
        else if(j < curr.size()) num1 = curr[j++];
        if(i < arr.size() && j < curr.size()) {
            if(arr[i] <= curr[j])  num2= arr[i++];
            else num2 = curr[j++];
        }
        else if(i < arr.size()) num2 = arr[i++];
        else if(j < curr.size()) num2 = curr[j++];
        long long sum = num1 + num2;
        curr.push_back(sum);
        cost += sum;
    }
    cout<<cost;
}
int main(){
    int n,k;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>k;
        arr.push_back(k);
    }
    minsum(arr);
    return 0;
}