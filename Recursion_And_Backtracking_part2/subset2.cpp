/*
Given an integer array nums that may contain duplicates, return all possible (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

 

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10

*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > ans;

void helper(vector<int> &arr, vector<int> &curr, int i){
    if(i == arr.size()){
        ans.push_back(curr);
        return;
    }

    curr.push_back(arr[i]);
    helper(arr, curr, i + 1);

    curr.pop_back();
    int idx = i + 1;
    while(idx < arr.size() && arr[idx] == arr[idx - 1]){
        idx++;
    }
    helper(arr, curr, idx);
}

vector<vector<int> > subsets(vector<int> &arr){
    vector<int> curr;
    helper(arr, curr, 0);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    vector<vector<int> > ans = subsets(arr);
    cout<<"The subsets are: "<<endl;
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}