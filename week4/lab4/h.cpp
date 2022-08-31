#include <iostream>
#include <cmath>
using namespace std;
struct node{
    int val;
    node * right;
    node * left;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
struct bst{
    private:
    node * _root;
    node * add(node * current,int x){
        if(current==NULL) return new node(x);
        if(x < current->val){
            current->left=add(current->left,x);
        }
        if(x>current->val){
            current->right=add(current->right,x);
        }
        return current;
    }
    bool find(node * current,int x){
        if(current==NULL) return false;
        if(current->val==x) return true;
        if(x<current->val) return find(current->left,x);
        return find(current->right,x);
    }
    void print(node * current,int level){
        if(current!=NULL){
            print(current->left,level+1);
            cout<<current->val<<" "<<level<<endl;
            print(current->right,level+1);
        }
    }
    int right_most(node * current){
        if(current==NULL) return -1;
        if(current->right==NULL) return current->val;
        return right_most(current->right);
    }
    int left_most(node * current){
        if(current==NULL) return -1;
        if(current->left==NULL) return current->val;
        return left_most(current->left);
    }
    node * del(node * current,int x){
        if(current==NULL) return NULL;
        if(current->val==x){
            if(current->right==NULL && current->left==NULL){
                delete current;
                return NULL;
            }
            else if(current->right!=NULL && current->left==NULL){
                node * temp= current->right;
                delete current;
                return temp;
            }else if(current->right==NULL && current->left!=NULL){
                node * temp=current->left;
                delete current;
                return temp;
            }else if(current->right!=NULL && current->left!=NULL){
                current->val=right_most(current->left);
                current->left=del(current->left,current->val);
            }
        }else if(x<current->val){
            current->left=del(current->left,x);
            return current;
        }else if(x>current->val){
            current->right=del(current->right,x);
        }
        return current;
    }
    int height(node* current){
        if(current == NULL ) return 0;
        return 1+max(height(current->left), height(current->right));
    }
    bool is_balanced(node * current){
        int lh;
        int rh;
        if(current==NULL){
            return 1;
        }
        lh = height(current->left);
        rh = height(current->right);
        if (abs(lh - rh) <= 1 && is_balanced(current->left) && is_balanced(current->right)) return 1;
        return 0;
    }
    public:
    bst(){
        _root=NULL;
    }
    void add(int x){
        if(find(_root,x)==false){
            node * res=add(_root,x);
            if(_root==NULL){
                _root=res;
             }
        }
    }
    void del(int x){
        del(_root,x);
    }
    void print(){
        print(_root,0);
        cout<<endl;
    }
    void is_balanced(){
        if(is_balanced(_root)) cout<<"YES";
        else cout<<"NO";
    }
};
int main(){
    bst * tree=new bst();
    int x;
    while(1){
        cin>>x;
        if(x==0) break;
        tree->add(x);
    }
    tree->is_balanced();
    return 0;
}