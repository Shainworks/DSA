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
int main(){
}