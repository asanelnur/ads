#include <iostream>
#include <vector>
using namespace std;
vector<int> f(string s){
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
    return pi;
}
int main(){
    int n;
    cin>>n;
    string str,pattern;
    vector<int> pi;
    for(int k=0;k<n;k++){
        cin>>str>>pattern;
        string n=pattern+"#"+str;
        //cout<<n<<endl;
        pi=f(n);
        int cnt=0;
        vector<int> ans;
        int m=pattern.length();
        for(int i=0;i<pi.size();i++){
            if(pi[i]==m){
                ans.push_back(i-2*m+1);
                cnt++;
            }
        }
        if(cnt!=0){
            cout<<cnt<<endl;
            for(int j=0;j<ans.size();j++){
                cout<<ans[j]<<" ";
            }
        }else{
            cout<<"Not Found";
        }
        cout<<endl;
    }
    return 0;
}