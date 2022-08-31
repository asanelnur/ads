#include <iostream>
#include <vector>
using namespace std;
vector<int> f(string t){
    int n=t.size();
    vector<int> pi(n);
    for(int i=0;i<n;i++){
        // cout<<t.substr(0,i+1);
        for(int k=0;k<=i;++k){
            // cout<<t.substr(0,k)<<" "<<t.substr(i-k+1,k)<<endl;
            if(t.substr(0,k)==t.substr(i-k+1,k)){
                pi[i]=k;
            }
        }
        // cout<<endl;
    }

    return pi;
}
int main(){
    string s;
    cin>>s;
    vector<int> pi=f(s);
    for(int i=0;i<pi.size();i++){
        cout<<pi[i]<<" ";
    }
    return 0;
}