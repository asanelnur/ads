#include <iostream>
#include <vector>
using namespace std;
class MyHashMap {
public:
    vector<vector<int> > v;
    int size=0;
    
    MyHashMap(){
    }
    
    void put(int key, int value) 
    {
        for(int i=0;i<size;i++)
        {
            if(v[i][0]==key)
            {
                v[i][1]=value;
                return;
            }
        }
        v.push_back({key,value});
        size++;
    }
    
    int get(int key) 
    {
        for(int i=0;i<size;i++)
            if(v[i][0]==key)
                return v[i][1];
        return -1;
    }
    
    void remove(int key) 
    {
        for(int i=0;i<size;i++)
        {
            if(v[i][0]==key)
            {
                v.erase(v.begin()+i);
                size--;
            }
        }
    }
};
int main(){
    MyHashMap* obj = new MyHashMap();
    vector<string> input;
    string s;
    while(cin>>s){
        if(s=="\n") break;
        input.push_back(s);
    }
    for(int i=1;i<input.size();i++){
        if(input[i]=="put"){
            obj->put(key,value);
            cout<<"null"<<" ";
        }else if(input[i]=="get"){
            int ans=obj->get(key);
            cout<<ans<<" ";
        }else{

        }
    }
    return 0;
}