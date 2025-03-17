#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // //This wil output
    // ****
    // ****
    // ****
    // ****
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // This wil output
    //*
    // **
    // ***
    // ****
    // *****
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 1; j <= i + 1; j++)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    // This wil output
    // 1
    // 12
    // 123
    // 1234
    // 12345
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }
    // This wil output
    // 1
    // 22
    // 333
    // 4444
    // 55555
    //  for (int i = 5; i > 0; i--)
    //     {
    //         for (int j = 1; j < i + 1; j++)
    //         {
    //             cout << "*";
    //         }
    //         cout << endl;
    //     }
    // This wil output
    // *****
    // ****
    // ***
    // **
    // *
    // for (int i = 5; i > 0; i--)
    // {
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // This wil output
    // 12345
    // 1234
    // 123
    // 12
    // 1
    // int n;
    // cin >> n;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <=n-i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < 2*i-1; j++)
    //     {
    //         cout << "*";
    //     }
    //     for (int j = 0; j <=n-i; j++)
    //     {
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    //This will output
//      *
//     ***
//    *****
//   *******
//  *********
// for (int i = n; i >= 0; i--)
// {
//     for (int j = 0; j <=n-i; j++)
//     {
//         cout << " ";
//     }
//     for (int j = 0; j < 2*i-1; j++)
//     {
//         cout << "*";
//     }
//     for (int j = 0; j <=n-i; j++)
//     {
//         cout << " ";
//     }
//     cout << endl;
// }
//This will ouput
// ********* 
//  *******
//   *****
//    ***
//     *
// for (int i = 0; i <= 2*n-1; i++)
// {
//     int stars =i;
//     if(i>n) stars = 2*n-i;
//     for (int j = 1; j <=stars; j++)
//     {
//         cout << "*";
//     }
//     cout << endl;
// }
//This will ouput
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// int start;
// for (int i = 0; i < n; i++)
// {
//     if(i%2==0){
//         start=1;
//     }
//     else
//     {
//         start=0;
//     }
    
//     for (int j = 0; j <= i; j++)
//     {
//         cout<<start;
//         start = 1 - start;
//     }
//     cout<<endl;
// }
//This will ouput
// 1
// 01
// 101
// 0101
// 10101
// for (int i = 0; i < n; i++)
// {
//     for (int j = 1; j <i+1; j++)
//     {
//         cout << j;
//     }
//     for (int j = 0; j <= 2*n-2*i-3; j++)
//     {
//         cout << " ";
//     }
//     for (int j = i; j >=1; j--)
//     {
//         cout << j;
//     }
//     cout << endl;
// }
//This will ouput
// 1      1
// 12    21
// 123  321
// 12344321
// for (int i = 0; i < n; i++)
// {
//     for (char ch = 'A'; ch < 'A'+(n-i-1); ch++)
//     {
//         cout<<ch;
//     }
//     cout<<endl;
// }
//This will ouput
// ABCD
// ABC
// AB
// A
// for (int i = 0; i < n; i++)
// {
//     char ch = 'A'+i;
//     for (int j = 0; j <i+1; j++)
//         {
//             cout << ch;
//         }
//     cout<<endl;
// }
//This will ouput
// A
// BB
// CCC
// DDDD
// EEEEE
    return 0;

}
