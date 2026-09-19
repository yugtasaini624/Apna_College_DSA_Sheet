/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<int> ans;

        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++){
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution obj;

    vector<int> ans = obj.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";

    for(int num : ans){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}