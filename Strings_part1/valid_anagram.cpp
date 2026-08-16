/*
Given two strings s and t, return true if t is an of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isAnagram(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();

    if(n1 != n2) return false;

    vector<int> freq(26, 0);

    for(char ch : s){
        freq[ch - 'a']++;
    }

    for(char ch: t){
        freq[ch - 'a']--;
    }

    for(int i = 0;i < 26;i++){
        if(freq[i] != 0){
            return false;
        }
    }

    return true;
}

int main(){
    string s1, s2;
    cout<<"Entre two strings: ";
    cin>>s1>>s2;

    cout<<"Valid anagram...? "<<isAnagram(s1, s2);
}