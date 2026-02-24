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

    void helper(int n,string cur,vector<string> &ans,int open,int close){       //  Base case: If current string length is equal to 2*n, add it to answer and return. If number of open parentheses is less than n, add an open parenthesis and make a recursive call. If number of close parentheses is less than number of open parentheses, add a close parenthesis and make a recursive call.
        if(cur.length()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n) helper(n,cur+'(',ans,open+1,close);      //If number of open parentheses is less than n, add an open parenthesis and make a recursive call
        if(close<open) helper(n,cur+')',ans,open,close+1);      //If number of close parentheses is less than number of open parentheses, add a close parenthesis and make a recursive call
    }
    vector<string> generateParenthesis(int n) {     // Generate all combinations of well-formed parentheses of length 2*n using recursion by keeping track of the number of open and close parentheses used so far and ensuring that at any point, the number of close parentheses does not exceed the number of open parentheses
        vector<string> ans;
        helper(n,"",ans,0,0);
        return ans;
    }
        int countSubsequenceWithTargetSum(vector<int>& nums, int k){        //Count the number of subsequences in an array that sum up to a target value k using recursion by keeping track of the current index, the current sum of the subsequence, and the count of valid subsequences found so far. At each step, we have two choices: include the current element in the subsequence or exclude it. We recursively explore both possibilities until we reach the end of the array, at which point we check if the current sum equals k and update our count accordingly.
        int cnt = 0;
        vector<int> arr = {};
        helper(0,arr,0,k,nums,cnt);
        return cnt;
    }
    void helper(int ind,vector<int> &arr,int sum,int k,vector<int> &nums, int &cnt){
        if(ind==nums.size()){       //Base case: If we have reached the end of the array, check if the current sum equals k and update count accordingly
         if(sum==k){
            cnt++;
        }
        return;
        }
        arr.push_back(nums[ind]);
        helper(ind+1,arr,sum+nums[ind],k,nums,cnt);     //Recursive call to include the current element in the subsequence and update the sum
        arr.pop_back();
        helper(ind+1,arr,sum,k,nums,cnt);       //Recursive call to exclude the current element from the subsequence and keep the sum unchanged
    }
    void helper(int ind, vector<int> &arr, int sum, int k,  
                vector<int> &nums) {

        if (ind == nums.size()) {       // Base case: If we have reached the end of the array, check if the current sum equals k and print the subsequence if it does
            if (sum == k) {
                for (int x : arr) cout << x << " ";
                cout << endl;
            }
            return;
        }

        // take
        arr.push_back(nums[ind]);
        helper(ind + 1, arr, sum + nums[ind], k, nums);
        arr.pop_back();

        // not take
        helper(ind + 1, arr, sum, k, nums);
    }

    void printSubsequenceWithTargetSum(vector<int>& nums, int k){       //Print all subsequences in an array that sum up to a target value k using recursion by keeping track of the current index, the current sum of the subsequence, and the current subsequence being formed. At each step, we have two choices: include the current element in the subsequence or exclude it. We recursively explore both possibilities until we reach the end of the array, at which point we check if the current sum equals k and print the subsequence if it does.
        vector<int> arr;
        helper(0, arr, 0, k, nums);
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {      //Check if there exists a subsequence in an array that sums up to a target value k using recursion by keeping track of the current index, the current sum of the subsequence, and a flag to indicate whether a valid subsequence has been found. At each step, we have two choices: include the current element in the subsequence or exclude it. We recursively explore both possibilities until we reach the end of the array or find a valid subsequence, at which point we return the result.
        // Code here
        vector<int> ans = {};       //Vector to store the current subsequence being formed
        bool flag = false;
        helper(0,n,ans,arr,k,flag,0);       //Recursive call to explore both possibilities of including or excluding the current element in the subsequence and updating the sum accordingly, while also checking if a valid subsequence has been found
        return flag;
    }
    bool helper(int ind,int &n,vector<int> &ans,vector<int> &arr,int k,bool &flag,int sum){
        if(sum==k){
            return flag = true;     //If the current sum equals k, set the flag to true and return
            }
        if(n==ind || sum>k){        //Base case: If we have reached the end of the array or the current sum exceeds k, return false
            return false;
        }
        if(!flag){
            ans.push_back(arr[ind]);
            helper(ind+1,n,ans,arr,k,flag,sum+arr[ind]);
            ans.pop_back();
            helper(ind+1,n,ans,arr,k,flag,sum);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {        //Generate all possible subsets of an array using recursion by keeping track of the current index and the current subset being formed. At each step, we have two choices: include the current element in the subset or exclude it. We recursively explore both possibilities until we reach the end of the array, at which point we add the current subset to our answer list.
        vector<vector<int>> ans = {};
        helper(0,nums,ans,{});
        return ans;
    }
    void helper(int ind, vector<int> nums,vector<vector<int>> &ans,vector<int> arr){
        if(ind==nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        helper(ind+1,nums,ans,arr);
        arr.pop_back();
        helper(ind+1,nums,ans,arr);
    }