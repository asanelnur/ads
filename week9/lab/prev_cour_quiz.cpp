#include <iostream>
#include <vector>
using namespace std;
bool pf(string s,string t,int k){
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
    int m=t.size();
    for(int i=0;i<n;i++){
        if(pi[i]==m) k--;
    }
    return k<=0;
}
int main(){
    //Задача узнать верно ли то что этот t встречается в строки s больше чем к раз?
    string t,s;int k;
    cin>>t>>k>>s;
    
    cout<<pf(s,t,k); 
    return 0;
}