#include <iostream>
#include <vector>
using namespace std;

class node{
  public:
   int val;
   node* left;
   node* right;

 node(int v){
     val = v;
     left = NULL;
     right = NULL;
 }
};

node* makeTree(node* root){

  int v,c;
  cin >> v >> c;

  root = new node(v);
  if(c == 2){
      root->left = makeTree(root->left);
      root->right = makeTree(root->right);
  }if(c == 1){
      root->left = makeTree(root->left);
  }
  return root;
}

void find_sum(node* root,int k,int &sum){
if(root==NULL) return;

if( k == 0) sum += root->val;

find_sum(root->left,k-1,sum);
find_sum(root->right,k-1,sum);

}

vector <int> left_view(node* root){



}

int main(){
    
    node* root = makeTree(root);
    int k;
    cin >> k;

    int sum = 0;
    find_sum(root,k,sum);
    cout <<sum;

    return 0;
    
}
