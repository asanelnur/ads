#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
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
            if(x<10){
                str+=char(x+'0');
            }else{
                string s;
                while(x>0){
                    int y=x%10;
                    s+=char(y+'0');
                    x=x/10;
                }
                for(size_t k=s.size()-1;k>=0;k--){
                    str+=s[k];
                }
            }
        }
        ans.push_back(make_pair(str,sum));

    }
    sort(ans.begin(),ans.end(),comp);
    vector<pair<string,int> > :: iterator it;
    string res;
    for(it=ans.begin();it!=ans.end();++it){
        res=(*it).first;
        for(size_t i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}