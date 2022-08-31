#include <iostream>
#include <vector>
#define nmax 1000
using namespace std;
long long p[nmax];

long long h(string s){
    long long hash=0;
    for(int i=0;i<s.length();i++){
        hash+=(s[i]-'a'+1)*p[i];
    }
    return hash;
}

int main(){
    p[0]=1;
    for(int k=1;k<nmax;k++){
        p[k]=p[k-1]*31;
    }
    int n;string s;long long hash;

    while(cin>>n && n!=0){
        int res=-1;
        vector<pair<string,int> > ans;
        vector<pair<string,long long> > v;
        for(int i=0;i<n;i++){
            cin>>s;
            hash=h(s);
            v.push_back(make_pair(s,hash));
        }
        cin>>s;
        int l=s.length();
        long long h[l];
        for(int i=0;i<l;i++){
            h[i]=(s[i]-'a'+1)*p[i];
            if(i>0){
                h[i]+=h[i-1];
            }
        }

        for(int i=0;i<n;i++){
            int cnt=0;
            int len=v[i].first.length();
            // cout<<v[i].first<<": ";
            for(int j=0;j+len-1<l;j++){
                long long cur=h[j+len-1];
                if(j>0){
                    cur-=h[j-1];
                }
                if(cur==v[i].second*p[j]){
                    // cout<<v[i].second*p[j]<<" "<<cur<<"| ";
                    cnt++;
                }
            }
            // cout<<cnt<<"#";
            if(cnt>=res){
                res=cnt;
                // cout<<res<<endl;
                ans.push_back(make_pair(v[i].first,cnt));
            }
        }
        cout<<res<<endl;
        for(int i=0;i<ans.size();i++){
            if(ans[i].second==res)
                cout<<ans[i].first<<endl;
        }
    }
    return 0;
}