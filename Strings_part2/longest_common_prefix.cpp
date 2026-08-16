/*
Write a function to find the longest common prefix string amongst an array of strings.If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

        string ans = "";

    int i = 0;
    while(i < first.size() && i < last.size()){
        if(first[i] != last[i]){
            break;
        }
        ans += first[i];
        i++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<string> strs(n);

    for(int i = 0;i < n;i++){
        cin>>strs[i];
    }

    cout<<"Longest common prefix = "<<longestCommonPrefix(strs);
}