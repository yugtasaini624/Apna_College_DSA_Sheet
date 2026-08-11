/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:
    -100.0 < x < 100.0
    -231 <= n <= 231-1
    n is an integer.
    Either x is not zero or n > 0.
    -104 <= xn <= 104
*/

#include<iostream>
using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1 && n < 0 && n % 2 == 0) return 1.0;
    if(x == 1 && n < 0 && n % 2 == 1) return -1.0;
    if(n == 1) return x;
    if(n == -1) return 1.0 / x;

    long binFor = (n < 0) ? -(long long)n : n;
    double ans = 1.0;

    if(n < 0){
        x = 1.0 / x;
    }

    while(binFor > 0){
        if(binFor % 2 == 1){
            ans *= x;
        }

        x *= x;
        binFor /= 2;
    }

    return ans;
}

int main(){
    double x;
    int n;
    cout<<"Enter number and its exponentional eg. 2 10 i.e 2 ^ 10:   ";
    cin>>x>>n;

    cout<<x<<"^"<<n<<" = "<<myPow(x, n);
    return 0;
}