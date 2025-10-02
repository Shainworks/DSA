#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) { //To remove the outermost parentheses from a valid parentheses string
        //O(n) solution
        string ans = "";
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(count>0) ans+=s[i];
                count++;
            }
            else if(s[i]==')'){
                count--;
                if(count>0) ans+=s[i];
            }
        }
        return ans;
    }
int main(){
   return 0;
}