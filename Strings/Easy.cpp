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
    string largestOddNumber(string num) {       //To find the largest odd number that can be formed by removing some digits from the given number
        //O(n) solution 
        int n = num.length() -1;
        for(int i=n;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
    string reverseWords(string s) {     //To reverse the words in a given string
        //O(n) solution
        int left = 0;
        int right = s.length()-1;
        string temp = "";
        string ans = "";
        while(left<=right){
            char ch = s[left];
            if(ch != ' '){
                temp += ch;
            }
            else {
                if(ans!="") ans = temp +' '+ ans;
                else ans = temp;
                temp="";
                while (left <= right && s[left] == ' ') left++;
                left--;
            }
            left++;
        }
        if(temp!=""){
            if(ans!="") ans = temp + ' ' + ans;
            else ans = temp;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {      //To find the longest common prefix among a list of strings
        //O(nlogn) solution
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";
        int minlength = min(first.size(),last.size());      //Finding the minimum length between the first and last strings to avoid out of bound errors
        for(int i=0;i<minlength;i++){
            if(first[i] != last[i])
            break;
            ans += first[i];
        }
        return ans;
    }
     bool isIsomorphic(string s, string t) {    //To find whether the two given strings are isomorphic or not
        int m1[256] = {0};
        int m2[256] = {0};
        int n = s.size();
        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]]){     //Checks the occurences of the characters
                return false;
            }
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
int main(){
   return 0;
}