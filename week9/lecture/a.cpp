#include <iostream>
#include <vector>
using namespace std;

vector<int> f(string s){
    int m=s.length();
    vector<int> p(m);
    for(int i=1;i<m;i++){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]){
            j=p[j-1];
        }
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
    return p;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    vector<int> p;
    string s,str;
    for(int i=0;i<m;i++){
        cin>>s;
        int len=s.length();int cnt=0;
        for(int j=0;j<n;j++){
            str=s+"#"+v1[j];
            p=f(str);
            for(int k=0;k<p.size();k++){
                if(p[k]==len){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}