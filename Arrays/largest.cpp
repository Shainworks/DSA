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