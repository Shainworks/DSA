#include<bits/stdc++.h>
using namespace std;
int main(){
   
}
const int mod = 1e9 +7;
long long power(long long x,long long y){       //Calculate x raised to the power y using fast exponentiation
        if(y==0) return 1;      //Base case
        long long ans=power(x,y/2);
        ans*=ans;
        ans%=mod;
        if(y%2)ans*=x;      //If y is odd, multiply ans by x
        ans%=mod;       //  Take modulo to prevent overflow
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        return ((power(5,even)%mod)*(power(4,odd)%mod)%mod);
    }
   double myPow(double x, int n) {      //Calculate x raised to the power n using fast exponentiation
         double ans = 1.0;
         long long NDUP = n;
         if(NDUP<0) NDUP = -1 * NDUP;       //If n is negative, make it positive for calculation
         while(NDUP){
            if(NDUP%2){     //If n is odd, multiply ans by x and decrease n by 1
                ans = ans*x;
                NDUP = NDUP-1;
            }
            else{       //If n is even, square x and divide n by 2
                x = x*x;
                NDUP = NDUP/2;
            }
         }
         if(n<0) ans = (double)(1.0)/(double)(ans);     //If n is negative, take reciprocal of ans
         return ans;
    }