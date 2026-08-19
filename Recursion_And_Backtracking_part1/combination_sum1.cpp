/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int> > ans;
set<vector<int> > s;

void helper(vector<int> &arr, vector<int> &curr, int i, int target){
    if(i == arr.size() || target < 0) return;

    if(target == 0){
        if(s.find(curr) == s.end()){
            ans.push_back(curr);
            s.insert(curr);
        }
        return;
    }

    // add one time only
    curr.push_back(arr[i]);
    helper(arr, curr, i + 1, target - arr[i]);

    // add multiple times
    helper(arr, curr, i, target - arr[i]);

    // not add
    curr.pop_back();
    helper(arr, curr, i + 1, target);

}

vector<vector<int> > combinationSum(vector<int> &arr, int target){
    vector<int> curr;
    helper(arr, curr, 0, target);
    return ans;
}

int main(){
    int n, target;
    cout<<"Enter the size and target of array: ";
    cin>>n>>target;

    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    vector<vector<int> > ans = combinationSum(arr, target);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

    return 0;
}