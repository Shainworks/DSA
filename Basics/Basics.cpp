#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    string str;
    cin>> x;
   getline(cin,str);     //This helps us to read the whole line even including the white spaces
   cout<<"The name is: "<<str;
   cout<< "Value of x:" <<x;
   return 0;
}
//Integer (int) stores 4 bytes of data
//long as 4bytes
//long long as 8 bytes
//unsigned short has 2 bytes
//float 4 bytes
//double 8 bytes
//long double 10 bytes
//String is used to store coleection of characters where as char is used to store single chracter because char takes up less space so it's ideal for creating for single character (256) characters
//Arrays are used when we wanna store multiple data types
//Array elements are stored in consecutive memory locations 
//When an array is not initialized it stores some garbage values
//WHen passing an array to the function it is always passed as reference