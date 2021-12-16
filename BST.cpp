#include <iostream>
using namespace std;

class node{
    public:
     int val;
     node* left;
     node* right;

    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

node* insert(node*, int);

node* makeBST(){

int d ;
cin >> d;
node* root = NULL;

while(d != -1){
 root = insert(root,d);
 cin >> d;
}
  return root;
}

node* insert(node* root, int d){

 if(root == NULL){
     root = new node(d);
     return root;
 }
 
 if(root->val <= d){
     root->left = insert(root->left,d);
 }else{
     root->right = insert(root->right,d);
 }
return root;
}

void print_inorder(node* root){

   if(root == NULL){
       return;
   }
  
  print_inorder(root->left);
  cout << root->val <<" ";
  print_inorder(root->right);

}

bool search(node* root,int x){

if(root == NULL) return false;
if(root->val == x) return true;

if(x > root->val)
 return search(root->right,x);
else
 return search(root->left,x);

}

int main(){
    
    node* root = makeBST();
    print_inorder(root);
    
    int x;
    cin >> x;

    if(search(root,x))
     cout <<"present !"<<endl;
    else
     cout <<"not present !"<<endl;
    
    return 0;
}
