#include<bits/stdc++.h>
using namespace std;
void numberextract(){
    int n;
    int lastdigit;
    cin>> n;
    while (n>0)         //For extracting the user inputted numbers
    {
        lastdigit = n%10;
        cout<<lastdigit;        
        n= n/10;
    }
}
void numberofdigits(){
    int n;
    int lastdigit;
    cin>> n;
    int count=0;
    while (n>0)         //For extracting the number of digits user as inputted
    {
        lastdigit = n%10;
        cout<<lastdigit<<endl;        
        n= n/10;
        count++;
    }
    cout<<count;
}
void reversenum(){
    int n;
    int lastdigit;
    cin>> n;
    int revnum=0;
    while (n>0)         //For reversing the digits user as inputted
    {
        lastdigit = n%10;     
        revnum = (revnum*10) + lastdigit;
        n= n/10;
    }
    cout<<revnum;
}
void palindrome(){
    int n;
    int lastdigit;
    cin>> n;
    int dup = n;            //This will store the original value of the n
    int revnum=0;
    while (n>0)         //For checking whther a number is palindrome or not
    {
        lastdigit = n%10;     
        revnum = (revnum*10) + lastdigit;
        n= n/10;
    }
    if (revnum == dup)
    {
        cout<<"It is palindrome";
    }
    else{cout<<"Not palindrome buddy";}
    
}
void armstrong(){
    int n;
    int lastdigit;
    cin>> n;
    int dup = n;            //This will store the original value of the n
    int armstrng=0;
    int count=0;
    int temp = n;
    while (temp>0)
    {
        temp = temp/10;
        count++;
    }
    
    while (n>0)         //For checking whther a number is armstrong or not....i.e,  sum of each digit raised to the power of the number of digits should equal n
    {
        lastdigit = n%10;     
        armstrng = armstrng + pow(lastdigit,count);
        n= n/10;
    }
    if (armstrng == dup)
    {
        cout<<"It is armstrong number";
    }
    else{cout<<"Not armstrong buddy";}
    
}
void printdivisors(){
    int divisor;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            cout<<i;
        }
        
    }
    
}
int main(){
    // numberextract();
    // numberofdigits();
    // palindrome();
    // armstrong();
    printdivisors();
    return 0;
}