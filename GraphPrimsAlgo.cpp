#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// prims algo to gate least weight in spanning tree ....

class graph{
  vector<pair<int,int>> *v;
  int n;

  public:

  graph(int x){
      n = x;
      v = new vector<pair<int,int>>[n];
  }

 void addedge(int w ,int x,int y){
   v[x].push_back(make_pair(w,y)); 
 }

 int prims(){

   bool *visited = new bool[n];
   for(int i = 0;i<n;i++) visited[i] = false;

   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

   q.push({0,0});
   int ans = 0;
   
   while(!q.empty()){
       auto t = q.top();
       q.pop();
       
       if(visited[t.second]){
        continue;
       }
       
       ans += t.first;
       visited[t.second] = true;

       for(auto x:v[t.second]){
        if(!visited[x.second]){
          q.push(x);
        }
       }

   }
   delete[]visited;
  return ans;
 }
  
};

int main() {
    graph g(4);
    g.addedge(1,0,1);
    g.addedge(2,1,2);
    g.addedge(4,2,3);
    g.addedge(1,0,3);

    cout << g.prims() <<endl;
}
