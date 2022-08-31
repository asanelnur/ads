#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool comp(pair<string,int> a, pair<string,int> b){
    if(a.second!=b.second) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    int n,m,x;
    cin>>n>>m;
    vector<pair<string,int> > ans;
    for(int i=0;i<n;i++){
        int sum=0;
        string str;
        for(int j=0;j<m;j++){
            cin>>x;
            sum+=x;
            str+=to_string(x);
            str+=" ";
        }
        ans.push_back(make_pair(str,sum));

    }
    sort(ans.begin(),ans.end(),comp);
    vector<pair<string,int> > :: iterator it;
    string res;
    for(it=ans.begin();it!=ans.end();++it){
        cout<<(*it).first;
        cout<<endl;
    }
    return 0;
}