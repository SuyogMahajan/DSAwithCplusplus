#include <iostream>
using namespace std;

//singly linked list:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class node{
 public:
     int d;
     node *nxt;
   
     node(int x){
         d = x;
         nxt = NULL;
     }  };

    void insert_head(node* &head,int x){
      if(head == NULL){
          head = new node(x);
          return;
      }

      node * n = new node(x);
      (*n).nxt = head;
      head = n;
    }
    int length(node *head){
    int ans  =0;
    while(head != NULL){
      head = head->nxt;
      ans++;
    }
    return ans;
  }

  void insert_tail(node *&head,int d){
    
   node *temp = head;

   while(temp->nxt != NULL){
     temp = temp->nxt;
   }
   temp->nxt = new node(d);
  }

   void insert_mid(node *&head,int p,int d){
     if(head ==NULL or p == 0) insert_head(head,d);
     else if(p == length(head)-1) insert_tail(head,d);
     else{
      node * nn = new node(d);
      node * temp = head;
      while(p > 0){
        temp = temp->nxt;
        p--;
      }
      nn->nxt = temp->nxt;
      temp->nxt = nn;
     }
  } 
 
 node* take_input(){
   node *head = NULL;
   int x;
   cin >> x;
   while(x != -1){
     insert_head(head,x);
     cin >> x;
   }
   return head;
 }

 istream& operator>>(istream& is,node*&head){
   head = take_input();
   return is;
 }

  void delete_head(node *&head){
    if(head == NULL) return;

    node *temp = head->nxt;
    delete head;
    head = temp;
  }
  void print(node *head){
      while(head != NULL){
          cout <<(*head).d<<" ";
          head = (*head).nxt;
      }
      cout << endl;
  }  

  ostream& operator<<(ostream &os,node *head){
    print(head);
    return os;
  }

  void reverse_ll(node *&head){
    node *p = NULL;
    node *c = head;
    node *n;
    while(c != NULL){
       n = c->nxt;
       c->nxt = p;
       p = c;
      c = n;
    }
    head = p;
  }

  node* rec_reverse(node *head){
  //base case
   if(head->nxt == NULL or head == NULL) return head;
  
  //rec case
   node *small_head = rec_reverse(head->nxt);
  
   //additional_process
   // 1 node *temp = small_head;                                                             /* 1 2 3 are number of methods */
   // 1 while(temp->nxt != NULL) temp = temp->nxt;
   /* 2  temp = head->nxt; */ 
   /* 1 2 *temp->nxt = head; */
  
   /*3*/ head->nxt->nxt = head;
   /*1 2 3*/head->nxt = NULL;
   return small_head;

  }

  node * mid_runner(node *head){
    
    if(head == NULL or head->nxt == NULL) return head;
    node *s = head;
    node *f = head->nxt;

    while(f != NULL and f->nxt != NULL){
      f = f->nxt->nxt;
      s = s->nxt;
    }
   
   return s;
  }

  node * kth_element(node *head,int k){
    node *f =head;
    node *s = head;
    int t =1;
    while(t != k){
     f = f->nxt;
     t++;
    }
    while(f->nxt != NULL){
      f = f->nxt;
      s = s->nxt;
    }
    return s;
  }

  node* merge(node *a,node *b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    node *c;
    if(a->d < b->d){
      c = a;
      c->nxt = merge(a->nxt,b);
    }else{
      c = b;
      c->nxt = merge(a,b->nxt);
    }
    return c;
  }

node* merge_sort(node* head){
if(head == NULL or head->nxt == NULL) return head;
node* mid = mid_runner(head);
node *b = mid->nxt;
mid->nxt =NULL;
node *a= head;
a = merge_sort(a);
b = merge_sort(b);

return merge(a,b);
}

bool is_cycle(node *head){
if(head == NULL or head->nxt == NULL) 
return false;  


node *s = head;
node *f = head;

while(f != NULL and f->nxt != NULL){
  f = f->nxt->nxt;
  s = s->nxt;

  if(s==f) return true;
}
return false;
}

node* get_tail(node *head){
  node *temp = head;

   while(temp->nxt != NULL){
     temp = temp->nxt;
   }
   return temp;
}

node* find_incorrect(node *head){

  node* s =head;
  node* f =head;

while(f != NULL and f->nxt != NULL){
    f = f->nxt->nxt;
    s = s->nxt;

    if(s == f){
     s= head;
      break;
    }

  }
while(s!=f){
  f = f->nxt;
  s = s->nxt;
}
return s;

}

int main() {
    node *head,*head1;
  /*  insert_head(head,1);
    insert_head(head,2);
    insert_head(head,3);
    insert_head(head,4);
    insert_mid(head,2,5);
    insert_tail(head,7);
    insert_tail(head,8);
    insert_tail(head,9);
*/  cin >> head ;
    cout <<head ;
    node*mid = mid_runner(head);
    node *tail = get_tail(head);

    tail->nxt = mid;

    if(is_cycle(head)){
      node *err = find_incorrect(head);
      cout << err->d <<endl;
    }
    else cout <<"non cyclic";


    //reverse_ll(head);

    //cout << head;
    //head = rec_reverse(head);
    //cout <<head;
    
/*    cout <<endl;
    delete_head(head);
    print(head);
        delete_head(head);
        cout <<endl;
        print(head);
  */  

    return 0;
}
