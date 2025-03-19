#include <bits/stdc++.h>
using namespace std;
void numberextract()
{
    int n;
    int lastdigit;
    cin >> n;
    while (n > 0) // For extracting the user inputted numbers
    {
        lastdigit = n % 10;
        cout << lastdigit;
        n = n / 10;
    }
}
void numberofdigits()
{
    int n;
    int lastdigit;
    cin >> n;
    int count = 0;
    while (n > 0) // For extracting the number of digits user as inputted
    {
        lastdigit = n % 10;
        cout << lastdigit << endl;
        n = n / 10;
        count++;
    }
    cout << count;
}
void reversenum()
{
    int n;
    int lastdigit;
    cin >> n;
    int revnum = 0;
    while (n > 0) // For reversing the digits user as inputted
    {
        lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }
    cout << revnum;
}
void palindrome()
{
    int n;
    int lastdigit;
    cin >> n;
    int dup = n; // This will store the original value of the n
    int revnum = 0;
    while (n > 0) // For checking whther a number is palindrome or not
    {
        lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }
    if (revnum == dup)
    {
        cout << "It is palindrome";
    }
    else
    {
        cout << "Not palindrome buddy";
    }
}
void armstrong()
{
    int n;
    int lastdigit;
    cin >> n;
    int dup = n; // This will store the original value of the n
    int armstrng = 0;
    int count = 0;
    int temp = n;
    while (temp > 0)
    {
        temp = temp / 10;
        count++;
    }

    while (n > 0) // For checking whther a number is armstrong or not....i.e,  sum of each digit raised to the power of the number of digits should equal n
    {
        lastdigit = n % 10;
        armstrng = armstrng + pow(lastdigit, count);
        n = n / 10;
    }
    if (armstrng == dup)
    {
        cout << "It is armstrong number";
    }
    else
    {
        cout << "Not armstrong buddy";
    }
}
void printdivisors()
{
    int divisor;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // printing the facttors of a given number
    {
        if (n % i == 0)
        {
            cout << i;
        }
    }
}
void primenumbers()
{
    int n;
    cin >> n;
    // printing whether a it's prime or not of a given number of a given number
    // Prime number is the one which has only two factors i.e, 1 and itself
    int count=0;
    for (int i = 1; i <= n; i++)
    {
    if (n % i == 0 )
    {
        count++;
    }
    }
    if (count == 2)
    {
        cout<<"Prime number";
    }
    else{
        cout<<"Not prime";
    } 
}
void GCD(){
    int n1,n2;
    cin>>n1>>n2;
    int gcd=1;              //prints the greatest common divisro of two numbers
    for (int i = 1; i <= min(n1,n2); i++)
    {
        if (n1%i==0 && n2%i==0)
        {
            gcd=i;
        }
        
    }
    cout<<gcd;
    
}
//Formula for euclidian:
//gcd(a,b)=gcd(a−b,b)if a>b
int main()
{
    // numberextract();
    // numberofdigits();
    // palindrome();
    // armstrong();
    // printdivisors();
    // primenumbers();
    GCD();
    return 0;
}