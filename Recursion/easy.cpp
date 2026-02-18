#include<bits/stdc++.h>
using namespace std;
int main(){
   
}
const int mod = 1e9 +7;
long long power(long long x,long long y){       //Calculate x raised to the power y using fast exponentiation
        if(y==0) return 1;      //Base case
        long long ans=power(x,y/2);
        ans*=ans;
        ans%=mod;
        if(y%2)ans*=x;      //If y is odd, multiply ans by x
        ans%=mod;       //  Take modulo to prevent overflow
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        return ((power(5,even)%mod)*(power(4,odd)%mod)%mod);
    }
   double myPow(double x, int n) {      //Calculate x raised to the power n using fast exponentiation
         double ans = 1.0;
         long long NDUP = n;
         if(NDUP<0) NDUP = -1 * NDUP;       //If n is negative, make it positive for calculation
         while(NDUP){
            if(NDUP%2){     //If n is odd, multiply ans by x and decrease n by 1
                ans = ans*x;
                NDUP = NDUP-1;
            }
            else{       //If n is even, square x and divide n by 2
                x = x*x;
                NDUP = NDUP/2;
            }
         }
         if(n<0) ans = (double)(1.0)/(double)(ans);     //If n is negative, take reciprocal of ans
         return ans;
    }
    void sortStack(stack<int> &st) {        //Sort a stack using recursion
        // code here
        if(st.empty()){     //Base case
            return;
        }
        int temp = st.top();
        st.pop();
        sortStack(st);      //Sort remaining stack
        sort(st,temp);      //Insert temp in sorted stack
    }
    void sort(stack<int> &st,int temp){     //Helper function to insert an element in sorted order in a stack
        if(st.empty() || st.top()<=temp){       //Base case: If stack is empty or top element is less than or equal to temp, push temp to stack
            st.push(temp);
            return;
        }
        int top = st.top();     //Store top element
        st.pop();
        sort(st,temp);      //Recursive call to sort remaining stack
        st.push(top);       //Push top element back to stack
    }
    void reverseStack(stack<int> &st) {     //Reverse a stack using recursion
        // code here
        if(st.empty()) return;      //Base case: If stack is empty, return
        int temp = st.top();
        st.pop();
        reverseStack(st);
        bottom(st,temp);
    }
    void bottom(stack<int> &st,int temp){       //Helper function to insert an element at the bottom of a stack
        if(st.empty()){     //Base case: If stack is empty, push temp to stack
            st.push(temp);
            return;
        }
        int top = st.top();     
        st.pop();
        bottom(st,temp);
        st.push(top);
    }
    vector<string> binstr(int n) {      //Generate all binary strings of length n using recursion
        // code here
        vector<string> ans = {};
        helper(n,"",ans);
        return ans;
    }
    void helper(int n, string curr, vector<string> &ans){       //Helper function to generate binary strings of length n by appending '0' and '1' to current string until length of current string is equal to n
        if(curr.length()==n){
            ans.push_back(curr);
            return;
        }
        helper(n,curr+'0',ans);     //Recursive call to append '0' to current string
        helper(n,curr+'1',ans);     //Recursive call to append '1' to current string
    }
    void helper(int n, string cur, vector<string> &ans) {       // Base case: If current string length is equal to n, add it to answer and return
        if (cur.length() == n) {
            ans.push_back(cur);
            return;
        }

        // Always allowed
        helper(n, cur + '0', ans);

        // Only if last char is NOT '1'
        if (cur.empty() || cur.back() != '1') {
            helper(n, cur + '1', ans);
        }
    }