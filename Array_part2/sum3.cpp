/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &arr){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int> > res;

    for(int i = 0;i < n;i++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0){
                j++;
            } else if(sum > 0){
                k--;
            } else{
                vector<int> vec(3);
                vec[0] = arr[i];
                vec[1] = arr[j];
                vec[2] = arr[k];

                res.push_back(vec);

                j++;
                k--;


                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    return res;
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements in array: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    vector<vector<int> > res = threeSum(arr);

    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}