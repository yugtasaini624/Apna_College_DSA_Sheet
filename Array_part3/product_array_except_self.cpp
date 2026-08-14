/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefix(n, 0);
    vector<int> suffix(n , 0);

    int pref = 1, suff = 1;

    for(int i = 0;i < n;i++){
        pref *= nums[i];
        prefix[i] = pref;
    }

    for(int i = n - 1;i >= 0;i--){
        suff *= nums[i];
        suffix[i] = suff;
    }

    vector<int> res(n, 0);

    for(int i = 0;i < n;i++){
        if(i == 0){
            res[0] = suffix[1];
        } else if(i == n - 1){
            res[n - 1] = prefix[n - 2];
        } else{
            res[i] = prefix[i - 1] * suffix[i + 1];
        }
    }

    return res;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter elements in array: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    vector<int> res = productExceptSelf(arr);
    for(int i = 0;i < n;i++){
        cout<<res[i]<<" ";
    }
}