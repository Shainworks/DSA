#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums, int k) {         //TO rotate k elements to the left in an array
    int n = nums.size();
    k = k % n;      //if k is greater than n then it should be lowered cuz if k = n then the same array will be rturned....so by modulus we get
    vector<int> temp;           //we get to know the exact times we want it to rotate
    for(int i=n-k;i<n;i++){
        temp.push_back(nums[i]);
    }
 for (int i = n - 1; i >= 0; i--) {
        if (i + k < n) {
             nums[i + k] = nums[i];  
            }
    }
        int j=0;
    for(int i=n-k;i<n;i++){
        nums[j] = temp[j];
        j++;
    }
    }
    void moveZeroes(vector<int>& nums) {        //moving the zeros to end
        int n = nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                nums[n-1-count] = nums[i];
                count++;
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
    }
    void moveZeroes(vector<int>& nums) {        //Optimized one
        int n = nums.size();
        int i = 0;
        int j = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1){
            return;
        }
        i = j+1;        //Because j will be having the first zeroth element then we can iterate after it
        while(i<n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
    }
    vector<int> findUnion(vector<int> &a, vector<int> &b) {     //finding union in two arrays with brute force
        // Your code here
        // return vector with correct order of elements
        set<int> st;
        for(int i=0;i<a.size();i++){
            st.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            st.insert(b[i]);
        }
        vector<int> unin;
        for(auto it:st){
            unin.push_back(it);
        }
        return unin;
    }
    vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {        //finding union in two arrays with optimal solution
        int i = 0, j = 0; // pointers
        vector < int > Union; // Uninon vector
        while (i < n && j < m) {
          if (arr1[i] <= arr2[j]) // Case 1 and 2
          {
            if (Union.size() == 0 || Union.back() != arr1[i])
              Union.push_back(arr1[i]);
            i++;
          } else // case 3
          {
            if (Union.size() == 0 || Union.back() != arr2[j])
              Union.push_back(arr2[j]);
            j++;
          }
        }
        while (i < n) // IF any element left in arr1
        {
          if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
          i++;
        }
        while (j < m) // If any elements left in arr2
        {
          if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
          j++;
        }
        return Union;
      }
      vector<int> findIntersection(vector<int> &a, vector<int> &b) {        //To check he intersection of two arrays
        vector<int> result;
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < b.size(); j++) {
                if(a[i] == b[j]) {
                    // Check if it's already in the result to avoid duplicates
                    bool alreadyPresent = false;
                    for(int k = 0; k < result.size(); k++) {
                        if(result[k] == a[i]) {
                            alreadyPresent = true;
                            break;
                        }
                    }
                    if(!alreadyPresent) {
                        result.push_back(a[i]);
                    }
                    break; // Move to next a[i] after first match
                }
            }
        }
        return result;
    }
    vector<int> findIntersection(vector<int> &a, vector<int> &b) {      //To check he intersection of two arrays (optimized)
        vector<int> result;
        int i = 0, j = 0;
    
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                i++;
            }
            else if(a[i] > b[j]) {
                j++;
            }
            else {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
            return result;
        } 
    
int main(){
    return 0;
}