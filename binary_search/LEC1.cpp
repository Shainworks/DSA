#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) { //To search for an element in a sorted array using binary search
    //O(logn) solution
        int n = nums.size();
        int low =0, high =n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else
            high = mid-1;
        }
        return -1;
    }
     int upperBound(vector<int>& arr, int target) { //To find the index of the first element greater than the target in a sorted array
        //O(logn) solution  
        int n = arr.size();
        int low=0,high=n-1,ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
     int lowerBound(vector<int>& arr, int target) {     //To find the index of the first element greater than or equal to the target in a sorted array
        //O(logn) solution
        int n = arr.size();
        int low=0,high=n-1,ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
     int searchInsertSort(vector<int>& arr, int target) {//To find the index where the target should be inserted in a sorted array
        //O(logn) solution
        // code here
        int n = arr.size();
        int low=0,high=n-1,ans=n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {        //To find the starting and ending position of a target in a sorted array
        //O(logn) solution
        int n = nums.size();
        int lb = lowerBound(nums,target);
        int up = upperBound(nums,target);
        if(lb==n || nums[lb]!=target){
            return {-1,-1};
        }
        return {lb,up-1};       // The upper bound returns the index of the first element greater than the target, so we subtract 1 to get the last occurrence of the target
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int first =-1,last =-1;
        //First occurence
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;   // We continue searching in the left half to find the first occurrence
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //Resetting bounds for sceond search
        low=0;
        high = n-1;
        //Second occurence
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid+1;        // We continue searching in the right half to find the last occurrence
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {first,last};
    }
     int search(vector<int>& arr, int target) {         //To search for an element in a rotated sorted array
        //O(logn) solution
        int n =  arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return mid;
            }
            //If the left half is sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && target<=arr[mid]){
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            //If the right half is sorted
            else{
                if(arr[mid]<=target && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
bool search2(vector<int>& arr, int target) {    //To search for an element in a rotated sorted array that may contain duplicates
        //O(logn) solution
         int n =  arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            //Edge case if mid = high = low
            if(arr[low] == arr[mid] && arr[mid] ==arr[high]){       //if mid is equal to low and high, we cannot determine which half is sorted, so we just move the pointers
                low++;                                              //if mmid is not equal to mid, then low and high are not equal, so we can determine which half is sorted
                high--;
                continue;
            }
            //If the left half is sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && target<=arr[mid]){
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            else{
                if(arr[mid]<=target && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
    int findMin(vector<int>& nums) {        //To find the minimum element in a rotated sorted array
        //O(logn) solution
        int n = nums.size();
        int mini = INT_MAX;
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){    //This part is sorted hence the lowest would be nums[low] itself
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else{//This part is sorted hence the lowest would be nums[mid] itself
                mini = min(mini,nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
    int findKRotation(vector<int> &arr) {       //To find the number of rotations in a rotated sorted array
        int n = arr.size();
        int mini = INT_MAX;
        int index = -1;
        for(int i=0;i<n;i++){
            if(arr[i]<mini){        //Finding the minimum element in the array which will be the point of rotation
                mini = arr[i];
                index = i;
            }
        }
        return index;
    }
    int findKRotation(vector<int> &arr) {       //To find the number of rotations in a rotated sorted array using binary search
        //O(logn) solution
        int n = arr.size();
        int low = 0, high = n-1;
        int index = -1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            //If left part is sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<mini){      
                    mini = arr[low];
                    index = low;
                }
                low = mid+1;
            }
            //If right part is sorted
            else{
                if(arr[mid]<mini){
                    mini = arr[mid];
                    index = mid;
                }
                high = mid-1;
            }
        }
        return index;
    }
    int singleNonDuplicate(vector<int>& arr) {      //To find the single non-duplicate element in a sorted array where every other element appears twice
        //O(n) solution  Brute force solution
        int n = arr.size();
        if(n == 1) return arr[0];   //If there is only one element then return that itself
        for(int i=0;i<n;i++){
            if(i==0){       //For the first element in the array
                if(arr[i]!=arr[i+1]){
                    return arr[i];
                }
            }
            else if(i == n-1){      //For the last element in the array
                if(arr[i]!=arr[i-1]){
                    return arr[i];
                }
            }
            else if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){      //For Elements existing in the middle
                return arr[i];
            }
        }
        return 0;
    }
    int singleNonDuplicate(vector<int>& nums) { // To find the single non-duplicate element in a sorted array where every other element appears twice using binary search
        //O(logn) solution Optimal solution
        int n = nums.size();
        //Edge cases to handle if there's only one element
        //For zero index 
        //For last index
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low = 1,high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]){
                return nums[mid];        //The unique element is found
            }
            //Eleminating the left half
            if((mid%2==1) && nums[mid-1]==nums[mid] || (mid%2==0) && nums[mid]==nums[mid+1]){
                low = mid+1;
            }
            //Eleminating the right half
            else{
                high = mid-1;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {        //To find a peak element in an array where a peak element is defined as an element that is greater than its neighbors
        //O(n) solution Brute force solution
        //A peak element is an element that is greater than its neighbors
        //For the first and last elements, we only need to check one neighbor to avoid out of bounds access
    int n = nums.size();
    if (n == 1) return 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (nums[i] > nums[i + 1]) return i;
        }
        else if (i == n - 1) {
            if (nums[i] > nums[i - 1]) return i;
        }
        else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            return i;
        }
    }

    return -1;
}
 int findPeakElement(vector<int>& nums) {       //To find a peak element in an array using binary search
        //O(logn) solution Optimal solution
        int n = nums.size();
        if (n == 1) return 0;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            //Handling edge cases for the first and last elements
            if (nums[low] > nums[low + 1]) return low;
            else if(nums[high]>nums[high-1]) return high;
            //Checking if mid is a peak element
            else if(nums[mid]>nums[mid+1] && nums[mid-1]<nums[mid]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid]){     //If the left neighbor is smaller than mid, then the peak element must be on the right side
                low = mid+1;
            }
            else    //If the right neighbor is smaller than mid, then the peak element must be on the left side
            {
                high = mid-1;
            }
        }
        return -1;
    }
    long long floorSqrt(long long n)  {     //To find the floor of the square root of a number using binary search
        //O(logn) solution  OPtimal solution
      int low = 1,high = n;
      long long ans;
      while(low<=high){
        long long mid = (low+high)/2;
        if((mid*mid) <= n){     //If mid squared is less than or equal to n, then mid is a possible answer
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
      }
      return ans;
    }
     int minEatingSpeed(vector<int>& piles, int h) {    //To find the minimum eating speed to finish all the piles of bananas in h hours
        //O(nlog(maxele)) solution
        int n = piles.size();
        for(int i=1;i<=maxele(piles);i++){
            int reqtime = calhours(piles,i);
            if(reqtime <= h){       //If the required time is less than or equal to h, then i is a possible answer
                //We need to find the minimum eating speed, so we return i
                return i;
            }
        }
        return 0;
    }
    int maxele(vector<int> arr){        //To find the maximum element in an array
        int n = arr.size();
        int MAXI = INT_MIN;
        for(int i=0;i<n;i++){
            MAXI = max(MAXI,arr[i]);
        }
        return MAXI;
    }
    int calhours(vector<int> arr, int hourly){      //To calculate the total hours required to finish all the piles of bananas at a given eating speed
        long long totalhrs = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            totalhrs += ceil((double)arr[i]/hourly);        //we use double to avoid integer division and use ceil to round up the hours required for each pile
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {     //To find the minimum eating speed to finish all the piles of bananas in h hours using binary search
        //O(nlog(maxele)) solution
        int low = 1;
        int high = maxele(piles);
        int ans = INT_MAX;
        while(low<=high){
            long long mid = (low+high)/2;
            long long totalhrs = calhours(piles,mid);
            if(totalhrs <= h){
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, long long m, long long k) {  //To find the minimum number of days required to make m bouquets with k flowers each
        //O(nlog(maxele)) solution
        int low = minele(bloomDay);
        int high = maxele(bloomDay);
        int ans = 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)==true){       //If it is possible to make m bouquets with k flowers each in mid days
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(m*k>bloomDay.size()){
            return -1;
        }
        else {
            return ans;
        }
    }
    bool possible(vector<int> arr,int days,int m,int k){        //To check if it is possible to make m bouquets with k flowers each in given days
        //O(n) solution
        int boquet = 0;
        int count = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=days){
                count++;
            }
            else{
                boquet += (count/k);
                count = 0;
            }
        }
        boquet += (count/k);
        if(boquet>=m){
            return true;
        }
        else{
           return false;
        }
    }
    int minele(vector<int> arr){
        int n = arr.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,arr[i]);
        }
        return mini;
    }
    int maxele(vector<int> arr){
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& nums, long long threshold) {   //To find the smallest divisor such that the sum of the quotients of each element divided by the divisor is less than or equal to the threshold
        //We can use binary search to find the smallest divisor
        //The minimum divisor can be 1 and the maximum divisor can be the maximum element in the array
        //We will check for each divisor if it satisfies the condition and return the smallest one
        //Brute force solution would be to check for each divisor from 1 to maxele(nums) and check if it satisfies the condition
     for(int i=1;i<=maxele(nums);i++){
        if(check(nums,i,threshold)==true){
            return i;
        }
     }   
     return -1;
    }
    bool check(vector<int> arr,int ele,long long threshold){        //To check if a divisor satisfies the condition
        //O(n) solution
        long long flag=0;
        for(int i=0;i<arr.size();i++){
            flag += ceil((double)arr[i]/(double)ele);
        }
        if(flag<=threshold){
            return true;
        }
        else{
            return false;
        }
    }
     int smallestDivisor(vector<int>& nums, long long threshold) {      //To find the smallest divisor such that the sum of the quotients of each element divided by the divisor is less than or equal to the threshold using binary search
        //O(nlog(maxele)) solution optimal solution
     //We can use binary search to find the smallest divisor
     int low = 1;
     int high = maxele(nums);
     int ans =1;
     while(low<=high){
        int mid = (low+high)/2;
        if(check(nums,mid,threshold)==true){
            ans = mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {        //To find the minimum capacity of the ship to ship all the weights within given days
        //O(nlog(sumele)) solution
        //brute force solution would be to check for each capacity from maxele(weights) to sumele(weights) and check if it satisfies the condition
        //The minimum capacity can be the maximum element in the weights array and the maximum capacity can be the sum of all the weights
        //We will check for each capacity if it satisfies the condition and return the smallest one
        for(int i=maxele(weights);i<=sumele(weights);i++){
            int daysrequired = check(weights,i);
            if(daysrequired<=days){
                return i;
            }
        }
        return -1;
    }
    int check(vector<int> arr,int capacity){        //To check how many days are required to ship all the weights with given capacity
        //O(n) solution
        int days = 1;
        int load = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(load+arr[i]>capacity){
                days = days +1;
                load = arr[i];
            }
            else{
                load += arr[i];
            }
        }
        return days;
    }
    int sumele(vector<int> arr){
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {    //To find the minimum capacity of the ship to ship all the weights within given days using binary search
        int low = maxele(weights);
        int high = sumele(weights);
        while(low<=high){//We will use binary search to find the minimum capacity
            //The minimum capacity can be the maximum element in the weights array and the maximum capacity can be the sum of all the weights
            //We will check for each capacity if it satisfies the condition and return the smallest one
            int mid = (low+high)/2;
            if(check(weights,mid)<=days){
               high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    int findKthPositive(vector<int>& arr, int k) {      //To find the kth missing positive number in a sorted array
        //O(n) solution optimal solution
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) low = mid+1;
            else high = mid -1;
        }
        return (high+1+k);      //The kth missing number will be high+1+k
    }
int main(){
}