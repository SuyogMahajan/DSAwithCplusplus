#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
   
   stack <char> a;

   for(int i=0;s[i] != '\0';i++){
      
    char c = s[i];

    // ( { [
    if(c == '(' or c == '{' or c == '['){
      a.push(c);
    }else{

      if(c == ')'){
         if(a.empty() or a.top() != '(')
          return false;
      }
       if(c == '}'){
         if(a.empty() or a.top() != '{')
          return false;
      }
       if(c == ']'){
         if(a.empty() or a.top() != '[')
          return false;
      }
     a.pop();
    }
   }

 return a.empty();
}

int main(){
    
    string s;
    cin >> s;

    if(isValid(s)){
        cout <<"Valid";
    }else{
        cout <<"invalid";    }

    return 0;
}