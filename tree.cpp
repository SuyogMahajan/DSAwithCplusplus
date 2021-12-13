#include <iostream>
#include <queue>
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

node* maketree(){
 int v;
 cin >> v;
 
 if(v == -1) return NULL;
 node* head = new node(v);
 
 head->left = maketree();
 head->right = maketree();

 return head;
}

//pre order :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void pre_print(node* &head){
// root left right 
if(head == NULL)
 return;

cout << head->val << " ";
pre_print(head->left);                                                                
pre_print(head->right);                                                               
}                                                                                 
                                                                                 
//post order ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void post_print(node* &head){
// left right root
if(head == NULL) return;

post_print(head->left);
post_print(head->right);
cout << head->val <<" ";

}

// in order ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void inw_print(node* &head){
// left root right
if(head == NULL) return;

inw_print(head->left);
cout << head->val <<" ";
inw_print(head->right);
}

// level order printing :::::::::::::::::::::::::::::::::::::::::::::::::::THIS APPROACH TAKES O(N^2) TIME !!!:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void lvl_print(node* &head,int k){

if(head == NULL) return;

if(k == 1){
 cout << head->val<<" ";
 return;
}
lvl_print(head->left,k-1);
lvl_print(head->right,k-1);

}

int height(node*&head){

if(head == NULL) return 0;

int ls = height(head->left);
int rs = height(head->right);

return max(ls,rs)+1;
}

int diatree(node* &head){

if(head == NULL) return 0;

int left = diatree(head->left);
int right = diatree(head->right);
left = max(left,right);
int withroot = height(head->left) + height(head->right);

return max(left,withroot);
}
//BFS (BINARY FIRST SEACH)::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::O(N) SOLUTION::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void bfs(node*&head){

  if(head == NULL) return;
  
  queue<node*> a;
  a.push(head);

  while(!a.empty()){
      node* t = a.front();
      cout <<t->val<<" ";

      if(t->left) a.push(t->left);
      if(t->right) a.push(t->right);
      a.pop();
  }  
}

// diameter efficient approach :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


pair <int,int> diameter(node* head){

pair<int,int> r;

if(head == NULL) { r.first = r.second = 0;
return r; }
pair <int,int> left = diameter(head->left);
pair <int,int> right = diameter(head->right);

r.first = max(left.first,right.first)+1;
r.second = max(left.first+right.first,max(left.second,right.second));

return r;
}

// replace with sums ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int sum(node*&head){

if(head == NULL) return 0;

head->val = head->val + sum(head->left) +sum(head->right);
return head->val;
}

void replace_sum(node* &head){
int x = sum(head);
}

// print all nodes at distance k ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void printatlvl(node* root,k){
  

}

int printall(node* root,node* target,int k){


}


int main() {
  
node* head = maketree();

/*pre_print(head);
cout <<endl;

post_print(head);
cout << endl;

inw_print(head);
cout <<endl;

cout << diatree(head) <<endl;
pair <int,int> r = diameter(head);
int s = max(r.first,r.second);
cout << s<<endl;
*/
pre_print(head);
replace_sum(head);
cout << endl;
pre_print(head);

    return 0;
}