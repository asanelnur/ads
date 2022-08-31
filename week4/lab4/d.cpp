#include <iostream>
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
    int cnt_numbers;
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
    void print(node * current){
        if(current!=NULL){
            print(current->left);
            cout<<current->val<<endl;
            print(current->right);
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
    public:
    bst(){
        _root=NULL;
        cnt_numbers=0;
    }
    void add(int x){
        if(find(_root,x)==false){
            cnt_numbers++;
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
        print(_root);
        cout<<endl;
    }
    void find_height(){
        cout<<height(_root);
    }
    void find_cnt_numbers(){
        cout<<cnt_numbers;
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
    tree->print();
    return 0;
}