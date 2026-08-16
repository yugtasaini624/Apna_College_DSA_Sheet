/*
Given two strings s and t of lengths m and n respectively, return the minimum window of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

string minWindow(string s, string t){
    int n1 = s.size();
    int n2 = t.size();

    if(n2 > n1) return "";

    vector<int> freq(128, 0);

    for(char ch: t){
        freq[ch]++;
    }

    int head = 0, begin = 0, end = 0;
    int d = INT_MAX;
    int counter = n2;

    while(end < n1){
        if(freq[s[end]] > 0){
            counter--;
        }
        
        freq[s[end]]--;
        end++;

        while(counter == 0){
            int currLen = end - begin;

            if(currLen < d){
                d = currLen;
                head = begin;
            }

            freq[s[begin]]++;
            
            if(freq[s[begin]] > 0){
                counter++;
            }

            begin++;
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}

int main(){
    string s1, s2;
    cout<<"Enter the strings : ";
    cin>>s1>>s2;

    cout<<minWindow(s1, s2);
}