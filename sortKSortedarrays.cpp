#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,pair<int,int>> pack;

vector <int> mergeAndsort(vector<vector<int>> v){

   priority_queue<pack,vector<pack>,greater<pack>> h;
   
   for(int i=0;i<v.size();i++){
    h.push({v[i][0],{i,0}});
   }
   
   vector <int> ans;
   
  while(!h.empty()){

    pack t = h.top();
    h.pop();
    int x = t.first;
    int r = t.second.first;
    int c = t.second.second;

    ans.push_back(x);
    if(c+1 < v[r].size()){
        h.push({v[r][c+1],{r,c+1}});
    }
  }
  return ans;
}

int main(){

  int n;
  cin >> n;

  vector <vector<int>> v;

  for(int i=0;i<n;i++){
      int m;
      cin >> m;
      vector <int> temp;

      for(int j=0;j<m;j++){
         int x;
         cin >> x;
         temp.push_back(x);
      }
      v.push_back(temp);
  }

  vector <int> ans = mergeAndsort(v);

  for(auto x: ans) cout << x <<" ";

  return 0;
}