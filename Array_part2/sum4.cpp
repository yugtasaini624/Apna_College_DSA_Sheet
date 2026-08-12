/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int target){
    vector<vector<int> > ans;

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for(int i = 0;i < n;i++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;

        for(int j = i + 1;j < n;j++){
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;

            while(k < l){
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                if(sum > target){
                    l--;
                } else if(sum < target){
                    k++;
                } else{
                    vector<int> res(4);
                    res[0] = arr[i];
                    res[1] = arr[j];
                    res[2] = arr[k];
                    res[3] = arr[l];

                    ans.push_back(res);

                    k++;
                    l--;

                    while(k < l && arr[k] == arr[k - 1]) k++;
                    while(k < l && arr[l] == arr[l + 1]) l--;
                }
            }
        }
    }

    return ans;
}

int main(){
    int n, target;
    cout<<"Enter size and target Value: ";
    cin>>n>>target;

    vector<int> arr(n);
    cout<<"Enter elements in array: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    vector<vector<int> > res = fourSum(arr, target);

    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}