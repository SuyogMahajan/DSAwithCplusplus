#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class graph{
  
  list<int>* l;

  public:
  	
   graph(int n){
    l = new list<int>[n];
   } 

   void connect(int x,int y){
   l[x].push_back(y);
   }
   
   void shortedpath_bfs(int dst){
     map<int,int> mp;
     
     for(int i = 0;i<=dst;i++){
      mp[i] = INT_MAX;
     }

     queue<int> q;

     q.push(0);
     mp[0] = 0;

     while(!q.empty()){

       int t = q.front();
       q.pop();

       for(auto x:l[t]){
         if(mp[x] == INT_MAX){
          q.push(x);
          mp[x] = mp[t]+1;
        }
       }
     }
     // for(auto x:mp){
     //  cout<<x.second <<endl;
     // }
     cout << mp[dst] <<endl;
   }

   

};

void solveit(int b[]){
 graph g(36);

 for(int i = 0;i<36;i++){

  for(int j =1;j<=6;j++){
    int k = i+j;
    k += b[k];
    if(k <=36){
       g.connect(i,k);
    }
  }
 } 
 g.shortedpath_bfs(35);
} 


int main(){

ios_base::sync_with_stdio(0);
cout.tie(0);



int board[36] = {0};

board[1] = 13;
board[13] = 21;
board[16] = -4;

solveit(board);

}