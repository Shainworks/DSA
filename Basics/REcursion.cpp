#include<bits/stdc++.h>
using namespace std;
void printname(int i, int n){
    if (i>n)     //Printing name n times using recursion
    {
        return;
    }
    cout<<"Darshan"<<endl;
    i++;
    printname(i,n);
}
void printnumber(int i, int n){
    if (i>n)     //Printing the number n times using recursion
    {
        return;
    }
    cout<<i<<endl;
    i++;
    printnumber(i,n);
}
void printrevnumber(int n){
    if (n<1)     //Printing the number n times in the reverse order using recursion
    {
        return;
    }
    cout<<n<<endl;
    n--;
    printrevnumber(n);
}
void printnumberbt(int n){
    if (n<1)     //Printing the number n times using recursion back tracking
    {
        return;
    }
    n--;
    printnumberbt(n);      //here i have placed the recursive function before the print statement....so it will output numbers while 
    cout<<n<<endl;          //coming backwards in the recursion tree
}
void printnumberrevbt(int i,int n){
    if (i>n)     //Printing the number n times in reverse order using recursion back tracking
    {
        return;
    }
    printnumberrevbt(i+1,n);      //here i have placed the recursive function before the print statement....so it will output numbers while 
    cout<<i<<endl;          //coming backwards in the recursion tree
}
void factorial(int n,int fact){
    if (n<1)                //Prints the factorial of the number
    {                       //THis is the parameterized recusrion way of solving
        cout<<fact;
        return;
    }
    factorial(n-1,fact=fact*n);
}
void revarray(int st, int end,int arr[]){
    //Here i will reversing an array by swapping the first and last members of the array useing teo pointers
    if (st>=end)
    {
        return;
    }
    int temp = arr[st];  // Store arr[st] in temp
    arr[st] = arr[end];  // Replace arr[st] with arr[end]
    arr[end] = temp;     // Replace arr[end] with temp (original arr[st])
    revarray(st+1,end-1,arr);
}
bool revstring(int i,string &s){
    if(i>= s.size()/2){             //Checking ehrther a string is palindrome ar not
        return true;
    }
    if (s[i] != s[s.size()-i-1])
    {
        return false;
    }
    return revstring(i+1,s);
}
int fibonacci(int n){
    if(n<=1){           //printing the fibonacci number
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n;
    cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    
    // printname(1,n);
    // printnumber(1,n);
    // printrevnumber(n);
    // printnumberrevbt(1,n);
    // factorial(n,1);
    // revarray(0,n-1,arr);        //end = n - 1 = 4 → End at the last index.
// In C++, when you pass an array to a function, it is passed by reference (not copied).
// This means any modifications to arr inside the function will affect the original array in main().
    // for (int i = 0; i < n; i++)
    // {
    //    cout<<arr[i];
    // }
    // string s = "madam";
    // cout<<revstring(0,s);
    cout<< fibonacci(n);
    return 0;
}