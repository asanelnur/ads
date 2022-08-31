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
                str+=' ';
            }else if(x<100){
                int y=x/10;
                str+=char(y+'0');
                y=x%10;
                str+=char(y+'0');
                str+=' ';
            }else if(x<1000){
                int y=x/100;
                str+=char(y+'0');
                x=x%100;
                y=x/10;
                str+=char(y+'0');
                y=x%10;
                str+=char(y+'0');
                str+=' ';
            }else{
                int y=x/1000;
                str+=char(y+'0');
                x=x%1000;
                y=x/100;
                str+=char(y+'0');
                y=x%100;
                y=x/10;
                str+=char(y+'0');
                y=x%10;
                str+=char(y+'0');
                str+=' ';
            }
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