#include <iostream>
#include <vector>
using namespace std;
int pf(string s,string t){
    s=t+"#"+s;

    int n=s.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]) j=j+1;
        pi[i]=j;
    }
    // for(int i=2;i<n;i++){
    //     cout<<pi[i]<<" ";
    // }
    // cout<<endl;
    int cnt=0;
    int ans=0;
    int i=2;
    int len=t.length();
    while(i<n){
        if(pi[i]!=len){
            i++;
            if(cnt>ans) ans=cnt;
            cnt=0;
        }
        else if(cnt==0){
            cnt++;
            i+=len;
        }
        else if(pi[i]==pi[i-1]){
            cnt++;
            i+=len;
        }
    }
    if(cnt>ans) ans=cnt;
    return ans;
}
int main(){
    string t,s;
    cin>>t>>s;
    
    cout<<pf(s,t); 
    return 0;
}