#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


// lets say we have to map cities with there names and distance with directions of way
// for this we will use hashmaps !!!

// class graph{

// public:
// 	unordered_map<string,list<pair<string,int>>> umap;
    
//   void  add_loc(string s,string t,bool bid,int d){
      
//        umap[s].push_back(make_pair(t,d));
//        if(bid)
//         umap[t].push_back(make_pair(s,d));
//     }

//   void print(){

//      for(auto x:umap){
//       cout << x.first <<" ->  ";

//       for(auto z:x.second){
//         cout << z.first <<","<<z.second<<" | ";
//       }
//       cout <<endl;
//      }
//   }
// };




//with only 0 to N indexed numbers

class graph{

int v;
list<int> *l;

void dfs_helper(int i,unordered_map<int,bool> &visited){

  cout<<i <<" ";
  
  for(auto x:l[i]){
    if(visited[x] != true){
      visited[x] = true;
      dfs_helper(x,visited);
    }
  }
}

public:

graph(int v){
	this->v = v+1;
	l = new list<int>(this->v);
}

void connect(int x,int y){
 l[x].push_back(y);
}


// void bfs(int x){

// unordered_map<int,bool> visited;



// queue<int> q;
// q.push(x);
// visited[x] = true;
// // cout << x <<" ";

// while(!q.empty()){
//   int t = q.front();
//   cout << t <<" ";
//   q.pop();

//   for(auto k:l[t])
//     if(!visited[k]){
//     q.push(k);
//     visited[k]=true;
//   }
// }

// }

// void shortedpath_bfs(int dst){
//      map<int,int> mp;
     
//      for(int i = 0;i<=dst;i++){
//       mp[i] = INT_MAX;
//      }

//      queue<int> q;

//      q.push(0);
//      mp[0] = 0;

//      while(!q.empty()){

//        int t = q.front();
//        q.pop();

//        for(auto x:l[t]){
//          if(mp[x] == INT_MAX){
//           q.push(x);
//           mp[x] = mp[t]+1;
//         }
//        }
//      }
//      // for(auto x:mp){
//      //  cout<<x.second <<endl;+
//      // }
//      cout << mp[dst] <<endl;
//    }

void dfs(int src){

unordered_map<int,bool> visited;

visited[src] = true;
dfs_helper(src,visited);
}

void rec_help(int i,map<int,bool> &visited,list<int>&ans){

   visited[i] = true;

   for(int k:l[i]){
    if(!visited[k]){
      rec_help(k,visited,ans);
    }
   }
  ans.push_front(i);
}


void topological_sort(){

list <int> ans;
map<int,bool> visited;

for(auto x : l){
  visited[x.first] = false;
}

for(auto x : l){
 if(!visited[x.first]){
  rec_help(x.first,visited,ans);
 }
}

 for(int x:ans){
  cout <<x<<" ";
 }
  cout <<endl;
}


void print(){

for(int x = 0;x<v;x++){
	list<int> lst = l[x];
	cout << x <<" -> ";
	for(auto t:lst)
		cout <<t<<",";
    cout << endl;
}
}

};



int main(){
// fast input output 
  ios_base::sync_with_stdio(false);
 // cin.tie(NULL);
  cout.tie(NULL);

 
// graph g;

// g.add_loc("hiv","jamner",false,6);
// g.add_loc("hiv","Jalgoan",false,35);
// g.add_loc("Jalgoan","jamner",true,40);
// g.add_loc("Jalgoan","pune",true,300);
// g.add_loc("Jalgoan","Bombay",false,500);
// g.add_loc("pune","Bombay",true,200);

// g.print();

 
graph g(5);

g.connect(0,1);
g.connect(0,4);
g.connect(0,5);
g.connect(0,2);
g.connect(0,3);
g.connect(5,3);
g.connect(1,5);
g.connect(2,1);
g.connect(4,2);

// g.print(); 
// cout << endl;
// g.bfs(3);
// cout <<endl;
// g.dfs(0);
cout <<endl;
g.topological_sort();
	return 0;
}
