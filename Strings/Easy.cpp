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
    bool rotateString(string s, string goal) {      //TO find whether the string s can be rotated to form the string goal
        //O(n) solution
        int n = s.length();
        for(int i=0;i<n;i++){
            string rotated = s.substr(i) + s.substr(0,i);       //Rotating the string by i positions
            if(rotated == goal)
            return true;
        }
        return false;
    }
     string frequencySort(string s) {       //To sort the characters in a string based on their frequency in descending order
        //O(nlogn) solution
        map<char,int> hashmap;
        vector<pair<char,int>> hashvec;
        for(int i=0;i<s.size();i++){
            hashmap[s[i]]++;
        }
        for(auto [ch,cnt]:hashmap){
            hashvec.push_back({ch,cnt});
        }
        auto comp = [&](pair<char,int> &a,pair<char,int> &b){       //Custom comparator to sort the vector based on the frequency of characters
            return a.second>b.second;
        };
        sort(hashvec.begin(),hashvec.end(),comp);
        string ans = "";
        for(auto [ch,cnt]:hashvec){
            ans.append(cnt,ch);     //Appending the character cnt number of times to the answer string
        }
        return ans;
    }
    int maxDepth(string s) {        //To find the maximum depth of nested parentheses in a valid parentheses string
        //O(n) solution
        int n = s.size();
        int count = 0;
        int Maxdepth = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                Maxdepth = max(Maxdepth,count);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return Maxdepth;
    }
    int romanToInt(string s) {      //To convert a roman numeral to an integer
        //O(n) solution
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='I' && s[i+1]=='V'){
                count = count +4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                count = count +9;
                i++;
            }
            else if(s[i]=='I'){
                count = count+1;
            }
            else if(s[i]=='V'){
                count = count +5;
            }
            else if(s[i]=='X' && s[i+1]=='C'){
                count = count +90;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L'){
                count = count +40;
                i++;
            }
            else if(s[i]=='X'){
                count = count +10;
            }
            else if(s[i]=='L'){
                count = count +50;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                count = count +900;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                count = count +400;
                i++;
            }
            else if(s[i]=='C'){
                count = count +100;
            }
            else if(s[i]=='D'){
                count = count +500;
            }
            else if(s[i]=='M'){
                count = count +1000;
            }
        }
        return count;
    }
int main(){
   return 0;
}