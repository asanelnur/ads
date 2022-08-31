//DNA_sequence
#include <iostream>
#include <vector>
#include <map>
using namespace std;
void findrepeatDNAsequence(string s){
    vector<string> ans;
    string t="";
    map<string,int> mp;
    map<string,int> m;
    for(int i=0;i<10;i++){
        t+=s[i];
    }
    mp[t]++;
    for(int i=10;i<s.length();i++){
        t.erase(0,1);
        t+=s[i];
        if(mp[t]!=0){
            if(m[t]==0){
                ans.push_back(t);
            }
            m[t]++;
        }
        mp[t]++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
void findrepeatDNAsequence2(string s){
    vector<string> ans2;
    long long n=s.length();
    vector<long long> h(n-10);
    long long p[n];
    p[0]=1;
    for(int i=1;i<10;i++){
        p[i]=p[i-1]*31; 
    }

    for(long long i=0;i+10-1<n;i++){
        long long hash=0;
        for(int j=i,k=0;j<i+10;j++){
            hash+=(s[j]-'A'+1)*p[k++];
        }
        h[i]=hash;
    }
    // for(long long i=0;i+10-1<n;i++){
    //     cout<<h[i]<<" ";
    // }
    map<long long,long long> mp2;
    map<long long,long long> m2;
    for(int i=0;i+10-1<n;i++){
        long long cur=h[i];
        if(mp2[cur]!=0){
            if(m2[cur]==0){
                ans2.push_back(s.substr(i,10));
            }
            m2[cur]++;
        }
        mp2[cur]++;
    }
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
}
int main(){
    string s;
    cin>>s;
    // findrepeatDNAsequence(s);
    // cout<<endl;
    findrepeatDNAsequence2(s);
    return 0;
}