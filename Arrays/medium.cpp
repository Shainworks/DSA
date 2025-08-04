#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {        //To sort 0's , 1's and 2's
    int n = nums.size();
    vector<int> temp(n); 
    for (int i = 0; i < n; i++) {
        temp[i] = nums[i];
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] == 0) {
            nums[index++] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] == 1) {
            nums[index++] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] == 2) {
            nums[index++] = 2;
        }
    }
}
vector<int> twoSum(vector<int>& nums, int target) {     //Better solution for finding indecies of 2sum using map
    int n = nums.size();            //O(nlogn)
    map<int,int> mpp;
     for(int i=0;i<n;i++){          // You're trying to find:
                                    //     a + b = target,
                                     //     so b = target - a → stored in more
         int a = nums[i];
        int more = target -a;
        if(mpp.find(more) != mpp.end()){
            return {mpp[more],i};
        }
        mpp[a] = i;
    }
return {};
}
string twoSumYesorNo(vector<int>& nums, int target) {
    int n = nums.size();        //This only returns whether the taget is there or not
    int left=0;                 //O(n)+O(nlogn)
    int right = n-1;
    sort(nums.begin(),nums.end());
    while(left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            return "Yes";
        }
        else if(sum < target){
            left++;
        }
        else {
            right++;
        }
    }
    return {};
}

//Dutch national flag algorithm
void sortColors(vector<int>& nums) {
    int n = nums.size();                //O(n) and no extra space is used
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int majorityElement(vector<int>& nums) {        //To find the majority element greater than n/2
    //O(n^2) solution
    int n =nums.size();
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
         if(count > n/2){
        return nums[i];
    }
    }
   return -1;
}
int majorityElement(vector<int>& nums) {        //To find the majority element greater than n/2
    //O(nlogn)+O(n) solution
    //O(n) space complexity
    int n =nums.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(auto it:mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}
int majorityElement(vector<int>& nums) {        //To find the majority element greater than n/2 using moore's voting algorithm
    //O(2n) solution
    //O(1) space complexity 
    //This algorithm is based on the fact that if we have a majority element, it will always be the last element remaining after all the pairs are cancelled out
    //This algorithm is also used to find the majority element in a stream of data
    int n =nums.size();
    int count=0;
    int ele;
    for(int i=0;i<n;i++){
        if(count ==0){
            count=1;
            ele = nums[i];
        }
        else if(nums[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int j=0;j<n;j++){       //This step won't be needed if we are sure that the majority element is present in the array
        if(ele==nums[j]){
            count1++;
        }
    }
    if(count1>n/2){
        return ele;
    }
    return -1;
}
int maxSubArray(vector<int>& nums) {        //To find the maximum subarray sum
    //O(n^3) solution
    //O(1) space complexity
    //Here INT_MIN is used to handle the case when all the elements are negative
    //SO that INT_MIN is always less than the maximum subarray sum
    //Here value of INT_MIN is -2147483648
        int n = nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                    maxi=max(sum,maxi);
                }
            }
        }
        return maxi;
    }
    int maxSubArray(vector<int>& nums) {        //This is the better solution
        //O(n^2) solution
        int n = nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
             int sum=0;
            for(int j=i;j<n;j++){
                    sum+=nums[j];
                    maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
        int maxSubArray(vector<int>& nums) {        //This is the best solution to find the maximum subarray sum using kadane's algorithm
        //O(n) solution
        //O(1) space complexity
        // int substart=-1;
        // int subend=-1;
        // int start;
        int n = nums.size();
        int maxi=INT_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            // if(sum==0){       //If the sum is 0, then we can start from the current element
            //     start=i;        //This is used to find the starting index of the maximum subarray
            // }
            sum+=nums[i];
            if(sum > maxi){     //If the sum is greater than the maximum subarray sum, then we update the maximum subarray sum
                maxi =sum;
                // substart=start;     //This will help to print the maximum subarray elements
                // subend=i;
            }
            if(sum<0){      //If the sum is negative, then we can ignore the previous elements and start from the next element
                sum=0;
            }
        }
        return maxi;
    }
    int maxProfit(vector<int>& prices) {        //To find the maximum profit from the stock prices
        //O(n) solution
        int n = prices.size();
        int profit=0;
        int mini = prices[0];
        for(int i=1;i<n;i++){
            int cost = prices[i] - mini;
            profit = max(profit,cost);      //This will give the maximum profit from the previous elements
            mini = min(mini,prices[i]);     //This will give the minimum price from the previous elements
        }
        return profit;
    }
    vector<int> rearrangeArray(vector<int>& nums) {     //To rearrange the array in such a way that the positive and negative elements are in alternate positions
        //O(n) solution
        //O(n) space complexity 
        int n = nums.size();
        vector<int> ans(n);
        int posindex = 0;
        int negindex = 1;
        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                ans[negindex] = nums[i];        //If the element is negative we put into the odd index
                negindex += 2;
            }
            else{
                ans[posindex] = nums[i];            //If the element is positive we put into the even index
                posindex += 2;
            }
        }
        return ans;
    }
    vector<int> rearrangeArray(vector<int>& nums) {     //To rearrange the array in such a way that the positive and negative elements are in alternate positions
        //Here postive and negative elements are not equally distributed
        //check written notes for more details
        //O(2n) solution
        //O(n) space complexity
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        if(pos.size() > neg.size()){
            for(int i=0;i<neg.size();i++){
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int index = neg.size() * 2;
            for(int i=neg.size();i<pos.size();i++){
                nums[index] = pos[i];
                index++;
            }
        }
        else{
            for(int i=0;i<pos.size();i++){
                nums[2*i] = pos[i];
                nums[2*i+1] = neg[i];
            }
            int index = pos.size() * 2;
            for(int i=pos.size();i<neg.size();i++){
                nums[index] = neg[i];
                index++;
            }
        }
        return nums;
    }
    void nextPermutation(vector<int>& nums) {       //To find the next permutation of the array in lexicographical order
        //O(3n) solution
        //O(1) space complexity
        //This algorithm is based on the fact that we need to find the first decreasing element from the right side and swap it with the next greater element from the right side
        int n = nums.size();
        int index =-1;
        for(int i=n-2;i>=0;i--){        //We find the first decreasing element from the right side
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index ==-1){     //If the array is in descending order, then we reverse the array to get the smallest permutation
            reverse(nums.begin(),nums.end());
            return;
        }   
        for(int i=n-1;i>index;i--){     //We find the next greater element from the right side and swap it with the first decreasing element
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());       //We reverse the elements after the first decreasing element to get the next permutation in lexicographical order
    }
    vector<int> leaders(vector<int>& arr) {        //To find the leaders in the array
        //A leader is an element which is greater than all the elements to its right    
        //O(n^2) solution
        //O(n) space complexity
        int n = arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            bool isleader = true;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    isleader = false;
                    break;
                }
            }
            if(isleader){
                    ans.push_back(arr[i]);
                }
        }
        return ans;
        
    }
    vector<int> leaders(vector<int>& arr) {     //To find the leaders in the array (optimized solution)
        int n = arr.size();
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){        
            if(arr[i] >= maxi){     
                ans.push_back(arr[i]);
            }
            maxi = max(maxi,arr[i]);        //We keep track of the maximum element from the right side
        }
        reverse(ans.begin(),ans.end());     //We reverse the array to get the leaders in the correct order
        return ans;
        
    }
        bool linearsearch(vector<int>& arr, int num) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == num) {
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& arr) {      //To find the longest consecutive sequence in the array
        //O(n^2) solution
        //O(1) space complexity
        //This solution uses linear search to find the next consecutive element
        int n = arr.size();
        int longest = 0;
        for(int i = 0; i < n; i++) {
            int count = 1;
            int x = arr[i];
            while(linearsearch(arr, x + 1)) {       //If the next consecutive element is found, we increment the count
                count++;
                x++;        // Increment x to check for the next consecutive element
            }
            longest = max(longest, count);
        }
        return longest;
    }
    int longestConsecutive(vector<int>& arr) {      //To find the longest consecutive sequence in the array better solution
        //O(nlogn) solution
        //O(1) space complexity
        //This solution uses sorting to find the next consecutive element
        //This solution is based on the fact that if we sort the array, then the next consecutive element will be the next element in the sorted array
        int n = arr.size();
        if(n==0) return 0;
        sort(arr.begin(),arr.end());
        int last_smaller = INT_MIN;
        int count =0;
        int longest = 0;
        for(int i=0;i<n;i++){
            if(arr[i]-1 == last_smaller){       //If the current element is the next consecutive element of the last smaller element, we increment the count
                //This is used to handle the case when there are duplicate elements in the array
                count = count +1;
                last_smaller = arr[i];
            }
            else if(last_smaller!=arr[i]){      //If the current element is not the next consecutive element of the last smaller element, we reset the count to 1
                count =1;
                last_smaller = arr[i];
            }
            longest = max(longest,count);
        }
        return longest;
    }
    int longestConsecutive(vector<int>&a) { //To find the longest consecutive sequence in the array using hash set (optimal solution)
        //Time complexity is O(3n) and 
        //space complexity is O(n)
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {      // Check if 'it' is the start of a sequence
            //it is a starting number, so we can find the consecutive numbers:
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {        // Check for the next consecutive number
                //if 'x+1' is present in the set, then we can increment the count:
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}
void setZeroes(vector<vector<int>>& matrix) {       //To set the entire row and column to 0 if an element is 0 (Brute force solution)
    //O(m*n) solution                                   this will only work if the matrix does not contain -1 in the matrix of 2d array  
        int m = matrix.size();      //rows
        int n = matrix[0].size();       //columns
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    markrows(i,n,matrix);
                    markcolumns(j,m,matrix);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    void markrows(int i,int n,vector<vector<int>>& matrix){     //To mark the entire row as -1 if an element is 0
        for(int j=0;j<n;j++){
            if(matrix[i][j] != 0){
                matrix[i][j] =-1;
            }
        }
    }
    void markcolumns(int j,int m,vector<vector<int>>& matrix){      //To mark the entire column as -1 if an element is 0
        for(int i=0;i<m;i++){
            if(matrix[i][j] != 0){
                matrix[i][j] =-1;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {       //To set the entire row and column to 0 if an element is 0 (Better solution)
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<int> row(n, 0);       //initialize row and column vectors to keep track of rows and columns that need to be set to 0
        std::vector<int> col(m, 0);        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){      //If an element is 0, we mark the corresponding row and column
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){       //If the row or column is marked, we set the element to 0
                    matrix[i][j]=0;
                }
            }
        }
    }
    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {     //Optimal solution to set the entire row and column to 0 if an element is 0
    //O(m*n) solution

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {  //To traverse the matrix in spiral order
        //O(m*n) solution
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int bottom = n-1;
        int right = m-1;
        vector<int> ans;
        while(top <= bottom && left <= right){          // Traverse the matrix in spiral order
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){        // Check if there are still rows left to traverse
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            }
            bottom--;
            if(left<=right){        // Check if there are still columns left to traverse
            for(int i=bottom;i>=top;i++){
                ans.push_back(matrix[i][left]);
            }
            }
            left++;
        }
        return ans;
    }
     int subarraySum(vector<int>& nums, int k) {    //To find the number of subarrays whose sum is equal to k
     //O(n^2) solution
     int n = nums.size();       //Better solution
     int count = 0;
     for(int i=0;i<n;i++){
        int sum =  0;
        for(int j=i;j<n;j++){
            sum += nums[j];
        if(sum == k){
            count++;
        }
        }
     }   
     return count;
    }
    int subarraySum(vector<int>& nums, int k) { //To find the number of subarrays whose sum is equal to k using prefix sum and hash map
     //O(n) solution
     int n = nums.size();
     unordered_map<int,int> mpp;
     mpp[0] = 1;
     int presum =0, cnt =0;
     for(int i=0;i<n;i++){
        presum += nums[i];
        int remove =  presum -k;
        cnt += mpp[remove];
        mpp[presum]+=1;
     }
     return cnt;
    }
int main(){
    return 0;
}