#include <iostream>
#include <string>
using namespace std;
 
struct stack{
    int storage[1000];
    int end=0;
    int sizze=0;
    int start=1;
    int lol=100;
    int push_back(int x){
        end = (end + 1)%lol;
        storage[end] = x;
        sizze++;
    }
    int push_front(int x){start = (start - 1+lol)%lol;
                    storage[start] = x;
                    sizze++;}               
                    
    void pop_back(){end = (end - 1+lol)%lol;
                sizze--;}
    void pop_front(){start = (start + 1)%lol;
                sizze--;}           
                
    int back() const{return storage[end];}
    int size() const{return sizze;}
    void clear(){end = 0;
                sizze = 0;
                start = 1;
                }
                
    int front() const{
        return storage[start];
}
    
};
 
int main() {
    
    stack storage;
    string s;
    int n;
    
    while(cin >> s){
        if(s == "push_back"){
            cin >> n;
            storage.push_back(n);
            cout << "ok\n";
        }else if(s == "push_front"){
            cin >> n;
            storage.push_front(n);
            cout << "ok\n";
        }
        
        else if(s == "pop_back"){
            if(storage.size()){
                cout << storage.back() << endl;
                storage.pop_back();
            }else{
                cout << "error\n";
            }
        }else if(s == "pop_front"){
            if(storage.size()){
                cout << storage.front() << endl;
                storage.pop_front();
            }else{
                cout << "error\n";
            }
        }else if(s == "front"){
            if(storage.size()){
                cout << storage.front() << endl;
            }
            else{
                cout << "error\n";
            }
        }
        
        
        
        else if(s == "back"){
            if(storage.size()){
                cout << storage.back() << endl;
            }else{
                cout << "error\n";
            }
        }else if(s == "size"){
            cout << storage.size() << endl;
        }else if(s == "clear"){
            storage.clear();
            cout << "ok\n";
        }else if(s == "exit"){
            cout << "bye\n";
            return 0;
        }
    }
    return 0;
}