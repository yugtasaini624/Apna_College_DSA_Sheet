/*
Given an array of strings strs, group the together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;

    unordered_map<string, vector<string> > mp;

    for(string str: strs){
        string s = str;
        sort(s.begin(), s.end());

        mp[s].push_back(str);
    }        

    for(auto &row: mp){
        ans.push_back(row.second);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    vector<string> strs(n);
    for(int i = 0;i < n;i++){
        cin>>strs[i];
    }

    vector<vector<string> > res = groupAnagrams(strs);

    cout<<"Ans = "<<endl;
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}