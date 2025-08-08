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
int main(){
}