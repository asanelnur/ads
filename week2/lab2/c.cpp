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
        int j=find(str);
        if(j!=-1){
            ans[j].second +=1;
        }else{
            ans.push_back(make_pair(str,1));
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