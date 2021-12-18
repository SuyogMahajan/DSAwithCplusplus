#include <bits\stdc++.h>
#include <vector>
using namespace std;

 int maxCoins(vector<int>& nums) {
        
     int dp[200][200];
     memset(dp,0,sizeof dp);
     int n = nums.size()-1;

     for(int i = 1;i<n;i++){
     	int r = 0,c = i;
      int val = INT_MAX;
      while(c<n){
        for(int j=r;j<c;j++){
         val = min(val,dp[r][j] + dp[j+1][c] + nums[r]*nums[j+1]*nums[c+1]);
        }
        dp[r][c] = val;
        r++,c++;
      }
     }
    return dp[0][n-1];
    }

int main(){



int n;
cin >> n;
vector<int> v;

for(int i = 0;i<n;i++){
	int x;
	cin >> x;
	v.push_back(x);
}

cout << maxCoins(v) <<endl;

}