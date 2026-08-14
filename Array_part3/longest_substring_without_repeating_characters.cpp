/*
Given a string s, find the length of the longest without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
    0 <= s.length <= 105
    s consists of English letters, digits, symbols and spaces.
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();

    if(n == 0 || n == 1) return n;

    unordered_map<char, int> mp;

    int maxLen = INT_MIN;
    int left = 0;

    for(int right = 0;right < n;right++){
        if(mp[s[right]] == 0){
            mp[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        } else{
            while(s[left] != s[right] && left < right){
                mp[s[left]]--;
                left++;
            }

            left++;
            maxLen = max(maxLen, right - left + 1);
        }
    }
    return maxLen;
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    cout<<"Max len with non repaeting characters = "<<lengthOfLongestSubstring(s);

    return 0;
}