/*
Given a string s, partition s such that every of the partition is a . Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<string> > ans;

bool isPalindrome(string part){
    int i = 0, j = part.size() - 1;
    while(i < j){
        if(part[i] != part[j]){
            return false;
        }

        i++;
        j--;
    }
    return true;

}

void helper(string s, vector<string> &curr){
    if(s.size() == 0){
        ans.push_back(curr);
        return;
    }

    for(int i = 0;i < s.size();i++){
        string part = s.substr(0, i + 1);
        if(isPalindrome(part)){
            curr.push_back(part);
            helper(s.substr(i + 1), curr);
            curr.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<string> curr;
    helper(s, curr);
    return ans;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    vector<vector<string> > ans = partition(s);
    cout<<"Sets of palindromes after partitioning are: "<<endl;
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}