#include<bits/stdc++.h>
using namespace std;
void largest(int arr[],int n){
    int maxelement = arr[0];
    for (int i = 0; i < n; i++)     //Time complexity is O(n)
    {
        if (arr[i] > maxelement)
        {
            maxelement = arr[i];
        }
    }
    cout<< maxelement;
}
int getSecondLargest(vector<int> &arr) {        //tc is O(nlogn)
    int n = arr.size();
    sort(arr.begin(), arr.end());
     int secondlargest = arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=secondlargest){
            return arr[i];
            break;
        }
    }
    return -1;
   
 }
 int getSecondLargest(vector<int> &arr) {       //TC is O(2n)
    int n = arr.size();
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    int secondlargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
 }
 int getSecondLargest(vector<int> &arr) {           //TC is O(n)
    int n = arr.size();
    int largest = arr[0];
    int slargest =-1;
    for(int i=0;i<n;i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]!=largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
 }
 int removeDuplicates(vector<int>& nums) {          //O(nlogn)
    set<int> unique_nums(nums.begin(), nums.end());  

    int index = 0;
    for (int num : unique_nums) {
        nums[index] = num;  
        index++;
    }

    return index;  
}
int missingNumber(vector<int>& nums) {      //Brute force for missing element in the array
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int flag=0;
        for (int j = 0; i < n-1; j++)
        {
            flag=1;
            break;
        }
        if(flag == 0){      //if the element is not found the flag will be marked as zero
            return nums[i];
        }
        
    }
}
int missingNumber(vector<int>& nums) {      //Better solution using hashing
        int n= nums.size();
        int hash[n+1] = {0};
        for (int i = 0; i < n-1; i++)
        {
            hash[nums[i]] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if(hash[i]==0){
                return i;       //This will return the elements which are not marked zero and those are the missing ones
            }
        }
}
int missingNumber(vector<int>& nums) {      //This is the optimal solution using the maths
    int n = nums.size();
    int sum = n*(n+1)/2;
    int res = 0;
    for(int val:nums) {
        res += val;
    }
    return (sum-res);
   }
   int singleNumber(vector<int>& nums) {        // To check that which number is not repeating twice
    int n = nums.size();
    int num=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==nums[i]){
                count++;
            }
        }
        if(count==1){
            num = nums[i];
            break;
        }
    }
     return num;
}
int singleNumber(vector<int>& nums) {       //This is the optimal solution for the above one using xor concept
    int result = 0;
    for (int i=0;i<nums.size();i++) {
        result = result^nums[i]; 
    }
    return result;
}
int getLongestSubarray(vector<int>& a, long long k) {       //Brute force method to fing the longest subaraay equal to sum k
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long sum = 0;
            for (int K = i; K <= j; K++) {
                sum += a[K];
            }

            if (sum == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int getLongestSubarray(vector<int>& a, long long k) {           //better solution for above with O(n)
    int n = a.size(); // size of the array.                     //This works for both negatives , positives and zeroes

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    
    return maxLen;
}
int longestSubarray(vector<int>& arr, long long k) {
    // code here                //This is the optimal solution but only for zeroes and postive numbers
    int n = arr.size();         //O(2n)
    long long sum = arr[0];
    int left=0;
    int right=0;
    int maxlen = 0;
    while(right < n){
        while(left <= right && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right<n) sum += arr[right];
    }
    return maxlen;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }
    largest(arr,n);
    return 0;
}