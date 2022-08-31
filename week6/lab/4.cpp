#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    int len,l;
    string s;

    for(int i=0;i<n;i++){
        cin>>len>>l;
        cin>>s;
        set<long long> myset;
        for(int i=0;i+l-1<s.length();i++){
            long long hash=0;
            long long p=1;
            for(int j=i;j<i+l;j++){
                // cout<<s[j];
                hash+=(s[j]-'a'+1)*p;
                p=p*31;
            }
            // cout<<" "<<hash<<" ";
            myset.insert(hash);
        }
        cout<<myset.size()<<endl;
    }
    return 0;
}