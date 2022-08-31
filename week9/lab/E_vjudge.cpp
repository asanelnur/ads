#include <iostream>
#include <vector>
using namespace std;
void PowerString(string s){
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
    int differenceLetters=s.substr(0,n-pi[n-1]).size();
    if(differenceLetters==n){
        cout<<1;
    }else{
        cout<<n/differenceLetters;
    }
}
int main(){
    string str;
    while(cin>>str && str!="."){
        PowerString(str);
        cout<<endl;
    }
    return 0;
}