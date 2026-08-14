/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    
    int prefix[n];
    prefix[0] = nums[0];

    for(int i = 1;i < n;i++){
        prefix[i] = nums[i] + prefix[i - 1];
    }
    
    int res = 0;

    unordered_map<int, int> mp;

    for(int i = 0;i < n;i++){
        if(prefix[i] == k){
            res++;
        }

        if(mp.find(prefix[i] - k) != mp.end()){
            res += mp[prefix[i] - k];
        }

        mp[prefix[i]]++;
    }

    return res;
}

int main(){
    int n, k;
    cout<<"Enter the size and val: ";
    cin>>n>>k;

    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<"Total subarrays with same sum = "<<subarraySum(arr, k);
}