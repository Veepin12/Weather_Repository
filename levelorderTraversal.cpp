#include <iostream>
using namespace std;
class node{
public:
    int val;
    node* left;
    node* right;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
        
    }
};
class tree{
public:
    node* root;
    tree(){
        
    }
    
        
    
    int level(node* root){
        if(root==NULL) return 0;
        return 1+ max(level(root->left),level(root->right));
        
    }
    void print(node* root,int curr,int level){
        if(root==NULL) return ;
        if(curr==level) {
            cout<<root->val<<"->";
            return;
        }
    
        print(root->left,curr+1,level);
        print(root->right,curr+1,level);
        
    }
    void levelorder(node* root){
        if(root==NULL) return ;
        int n= level(root);
        for(int i=1;i<=n;i++){
            print(root,1,i);
            cout<<endl;
        }
        
        
    }
};


int main(){
    tree t;
    node* a=new node(1);
    node* b=new node(2);
    node* c=new node(3);
    node* d=new node(4);
    node* e=new node(5);
    node* f=new node(6);
    node* g=new node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
     
    cout<< t.level(a)<<endl;
    t.print(a,1,2);
    cout<<endl;
    t.levelorder(a);
    cout<<endl;
}
