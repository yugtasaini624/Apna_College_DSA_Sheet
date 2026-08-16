/*
A string is called a happy prefix if it is a non-empty prefix which is also a suffix (excluding itself).Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Constraints:
    1 <= s.length <= 105
    s contains only lowercase English letters.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestHappyPrefix(string s){
    int n = s.size();
    vector<int> dp(n, 0);

    int i = 1, len = 0;
    while(i < n){
        if(s[len] == s[i]){
            dp[i] = ++len;
            i++;
        } else if(len > 0){
            len = dp[len - 1];
        } else{
            dp[i] = 0;
            i++;
        }
    }
    return s.substr(0, dp.back());
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    cout<<longestHappyPrefix(s);
}