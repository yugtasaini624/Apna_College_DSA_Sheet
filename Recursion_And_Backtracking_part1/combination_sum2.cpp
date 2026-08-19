/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.


Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*/


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
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

    // not add
    curr.pop_back();
    while(i + 1 < arr.size() && arr[i] == arr[i + 1])
        i++;
    helper(arr, curr, i + 1, target);

}

vector<vector<int> > combinationSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
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