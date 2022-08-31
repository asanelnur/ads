#include <iostream>
using namespace std;
int max_dis=-1;
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
    public:
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
    void add(int x){
        node * res=add(_root,x);
        if(_root==NULL){
            _root=res;
        }
    }
    node * get_root(){
        return _root;
    }
    int  BTMaxDistance(node * item){    
        if (item == NULL){
            return -1;
        }else{
            int l = BTMaxDistance(item->left);
            int r = BTMaxDistance(item->right);
            int distance = l + r + 2;
            if(distance>max_dis) max_dis=distance;
            if(l>r) return l+1;
            return r+1;
        }
    }
};
int main(){
    bst * tree=new bst();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        tree->add(a[i]);
    }
    tree->BTMaxDistance(tree->get_root());
    cout<<max_dis+1;
    return 0;
}