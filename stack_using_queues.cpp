#include<iostream>
#include <queue>
using namespace std;

template <typename t>

class stacks{

 private:
  queue <t> a;
  queue <t> b;

 public:
  void push(t x){
    a.push(x);
  }

  void pop(){
   //copy a to b till end-1
    int n = a.size();

    while(n != 1){
     b.push(a.front());
     a.pop();
     n--;
    }
   //pop front 1st
    a.pop();
   //swap them
    swap(a,b);
  }
  
  t get_back(){
      //copy a to b till end-1
   int n = a.size();

    while(n != 1){
     b.push(a.front());
     a.pop();
     n--;
    }
   
   //stor front 1st
   t temp = a.front();
   a.pop();
// copy that to
   b.push(temp);
   //swap them
    swap(a,b);
 //return stored
   return temp;
  } 

  bool empty(){
      return a.size() == 0;
  }

};


int main(){
    stacks <int> a;
   int n;
   cin >> n;

   while(n--){
       int x;
       cin >> x;
       a.push(x);
   }

   while(!a.empty()){
       cout << a.get_back()<<endl;
       a.pop();
   }
    return 0;
}