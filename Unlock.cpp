#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void defuse_bomb(vector<int> &v,int k){
    
    unordered_map<int,int> mp;

    for(int i=0;i<v.size();i++){
        mp[v[i]] = i;
    }
    
    int i = 0;
    int j = v.size();
    while(k){
      
      int idx = mp[j--];
      if(idx == i){
          i++;
          continue;
      }
      mp[v[idx]] = i;
      mp[v[i]] = idx;
      swap(v[idx],v[i]);
      i++;
      k--;
    }
}

int main() {
    
    int n,k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0;i<n;i++){
     int x;
     cin >> x;
     v[i] = x;
    }
    
    defuse_bomb(v,k);
    for(int x : v){
        cout << x <<" ";
    }

    return 0;
}
