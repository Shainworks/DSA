//Here this code contains
//Selection sort
//Bubble sort
//Insertion sort
#include <bits/stdc++.h>
using namespace std;
void selection(int arr[],int size){
    
    for (int i = 0; i < size - 1; i++)
    {
        int minindex=i;
        for (int j = i; j < size; j++)
        {
            if (arr[j]<arr[minindex])
            {
                minindex = j;
            }
            
        }
        swap(arr[i],arr[minindex]);
        
    }
    
}
void bubble(int arr[], int size) {
    bool swapped; // To check if a swap has occurred
    for (int i = 0; i < size - 1; i++) { // OUTER LOOP - Controls the number of passes
        for (int j = 0; j < size - i - 1; j++) { // INNER LOOP - Moves the largest element to the end
            if (arr[j] > arr[j + 1]) { // Compare adjacent elements
                swap(arr[j], arr[j + 1]); // Swap if they are in the wrong order
                swapped=true;
            }   //here -i in inner loop is to not to check for the last element cuz it's already sorted
        }       //also here in inner loop -1 is placed so that the if condition j+1 wo'nt read the index which has no value
        if (!swapped)
        {
            break;
        }
        
    }
}
void insertion(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        int j=i;
        while (j>0 && arr[j-1]> arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    // selection(arr,size);
    // bubble(arr,size);
    insertion(arr,size);
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i];
    }
    
    return 0;
}