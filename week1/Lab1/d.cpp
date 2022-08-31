#include <iostream>
#include <queue>
using namespace std;
int main(){
    int c;
    string name;
    queue <pair <int,string> > class_nine,class_ten,class_eleven;
    while(cin>>c>>name){
        if(c==9) class_nine.push(make_pair(c,name));
        else if(c==10) class_ten.push(make_pair(c,name));
        else if(c==11) class_eleven.push(make_pair(c,name));
    }
    while(!class_nine.empty()){
        cout<<class_nine.front().first<<" "<<class_nine.front().second<<endl;
        class_nine.pop();
    }
    while(!class_ten.empty()){
        cout<<class_ten.front().first<<" "<<class_ten.front().second<<endl;
        class_ten.pop();
    }
    while(!class_eleven.empty()){
        cout<<class_eleven.front().first<<" "<<class_eleven.front().second<<endl;
        class_eleven.pop();
    }
    return 0;
}