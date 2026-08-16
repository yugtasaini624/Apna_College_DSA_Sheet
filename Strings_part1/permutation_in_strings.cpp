/*
Given two strings s1 and s2, return true if s2 contains a of s1, or false otherwise.In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2){
    int n1 = s1.size(), n2 = s2.size();

    if(n1 > n2) return false;

    vector<int> freq1(26,0);
    vector<int> freq2(26, 0);

    for(char ch: s1){
        freq1[ch - 'a']++;
    }

    int counter = 0;
    for(char ch : s2){
        if(counter == n1) break;
        freq2[ch - 'a']++;
        counter++;
    }

    if(freq1 == freq2) return true;

    int left = 0;
    for(int right = n1;right < n2;right++){
        freq2[s2[right] - 'a']++;
        freq2[s2[left] - 'a']--;

        left++;

        if(freq1 == freq2) return true;
    }

    return false;
}

int main(){
    string s1, s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;

    cout<<"Contain palindrome of s1 in s2???  "<<checkInclusion(s1, s2);
}