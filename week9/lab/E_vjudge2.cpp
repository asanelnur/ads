#include <iostream>
#include <vector>
using namespace std;
vector<int> pf(string s){
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
    string str;
    while(cin>>str && str!="."){
        vector<int> v=pf(str);
        int n=(v.size()-v[str.size()-1]);
        if(v.size()%n!=0){
            cout<<1<<endl;
        }else{
            cout<<v.size()/n<<endl;
        }
    }
    return 0;
}