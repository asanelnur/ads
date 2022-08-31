#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
vector<pair<string,int> > ans;
int find(string s){
    for(int i=0;i<ans.size();i++){
        if(ans[i].first==s) return i;
    }
    return -1;
}
bool comp(pair<string,int> a, pair<string,int> b){
    if(a.second!=b.second) return a.second>b.second;
    return a.first<b.first;
}
int main(){
    ofstream out;
    ifstream in;
    in.open("input.txt");
    out.open("output.txt");
    string str;
    while(in>>str){
        string abc="";
        for(long unsigned int i=0;i<str.size();i++)
            if(str[i]!='.'&&str[i]!=','&&str[i]!=':'&&str[i]!=';'&&str[i]!='!'&&str[i]!='?'){
                if(65<=int(str[i])&&int(str[i])<=90)
                    str[i]=char(int(str[i])+32);
                 abc+=str[i];
            }
        if(abc!=""){
            int j=find(abc);
            if(j!=-1){
                ans[j].second +=1;
            }else{
                ans.push_back(make_pair(abc,1));
            }
        }
    }
    sort(ans.begin(),ans.end(),comp);
    vector<pair<string,int> > :: iterator it;
    for(it=ans.begin();it!=ans.end();++it){
        out<<(*it).first<<" "<<(*it).second<<endl;
    }
    out.close();
    return 0;
}