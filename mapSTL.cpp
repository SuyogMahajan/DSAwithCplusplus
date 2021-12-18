#include <iostream>
#include <vector>
#include <map>
#include <unordered_map> // hash Tables !!!
#include <string>
using namespace std;

/*

class student{
    public :
     string fname;
     string lname;
     int rollno;

     student(string s1,string s2,int r){
         fname = s1;
         lname = s2;
         rollno = r;
     }

   // to compare 2 students 

   bool operator==(const student&s)const{
       return s.rollno == rollno ? true : false;
   }
};

class hashfun{
public:
 size_t operator()(const student &s)const{
     return s.fname.length()+s.lname.length();
 }
};
*/
    int subarraySum(vector<int>& nums, int k) {

     unordered_map<int,int> m;

     int sum = 0;
     int ans = 0;
     for(int i=0;i<nums.size();i++){
       sum += nums[i];

       if(sum == k){
           ans = max(ans,i+1);
       }
       if(m.find(sum-k) != m.end()){
           ans = max(ans,i-m[sum-k]);
       }else{
           m[sum] = i;
       }
     }   
        return ans;  
    }

int
main()
{

   int n;
   cin >> n;

   vector<int> v;
   for(int i=0;i<n;i++){
       int x;
       cin >> x;
       v.push_back(x);
   }

   int k;
   cin >> k;

   cout << subarraySum(v,k) <<endl;

   /* map <string ,vector<long long int>> phone_book;
    
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        int m;
        cin >> s >> m;
        vector<long long int> temp;
        for(int j=0;j<m;j++){
           long long int t;
           cin >> t;
           temp.push_back(t);
        }
        phone_book[s] 
        = temp;
    }

  string s;
  cin >> s;
  cout << s <<endl;

  for(int i=0;i<phone_book[s].size();i++){
      cout << phone_book[s][i] <<endl;
  }
 cout << endl;  

  unordered_map<student,int,hashfun> mp;

  student s1("suyog","mahajan",12);
  student s2("kiran","patil",18);
  student s3("aditya","bindu",05);
  student s4("rahul","lamb",11);
  student s5("ankit","xyz",9);

  mp[s1] = 15;
  mp[s2] = 10;
  mp[s3] = 101;
  mp[s4] = 102;
  mp[s5] = 17;  
  
  for(auto x:mp){
      cout << x.first.fname <<" "<<x.second <<endl;
  }
    // mapstl implemented

    /*  map<string,int> mp;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
     string s;
     int v;

     cin >> s>> v;
     mp.insert({s,v});
    }
   cout << endl;
    
    for(auto x : mp){
        cout << x.first <<" : "<<x.second <<endl;
    }
       // map stores elements in sorted order but unorderd maps are hash tables they store randomly !!!! reffer to HashTable.cpp file

      unordered_map<string,int> ump;

    int m;
    cin >> m;

    for(int i=0;i<m;i++){
     string s;
     int v;

     cin >> s>> v;
     ump.insert({s,v});
    }
   cout << endl;
    
    for(auto x : ump){
        cout << x.first <<" : "<<x.second <<endl;
    }
*/

    return 0;
}