/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

 

Constraints:

    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int> &nums, int st, int end, int mid) {
        vector<int> temp;

        int i = st;
        int j = mid + 1;

        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = 0; i < temp.size(); i++) {
            nums[i + st] = temp[i];
        }
    }

    void mergeSort(vector<int> &nums, int i, int j) {
        if(i >= j) {
            return;
        }

        int mid = i + (j - i) / 2;

        mergeSort(nums, i, mid);
        mergeSort(nums, mid + 1, j);

        merge(nums, i, j, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {

    vector<int> nums = {5, 2, 3, 1};

    Solution obj;

    vector<int> ans = obj.sortArray(nums);

    cout << "Sorted Array: ";

    for(int num : ans) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}