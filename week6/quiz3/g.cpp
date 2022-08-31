#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.length();

    vector<long long> p_pow(500001);
    p_pow[0]=1;
    for(int i=1;i<n;i++){
        p_pow[i]=p_pow[i-1]*31;
    }

    long long hash_s=0;
    for(int i=0;i<n;i++){
        hash_s+=(s[i]-'a'+1)*p_pow[i];
    }
    
    int m;
    cin>>m;
    vector<pair<string,long long> > v(m);
    string t;
    for(int i=0;i<m;i++){
        cin>>t;
        long long ht=0;
        for(int j=0;j<t.size();j++){
            ht+=(t[j]-'a'+1)*p_pow[j];
        }
        // cout<<ht<<endl;
        v[i]=make_pair(t,ht);
    }
    // for(int i=0;i<m;i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int l1=v[i].first.length();
            // cout<<(v[i].second+v[j].second*p_pow[l1])<<" "<<hash_s<<endl;
            if((v[i].second+v[j].second*p_pow[l1])==hash_s){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}