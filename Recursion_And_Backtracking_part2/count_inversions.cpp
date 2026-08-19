/*
You are given an integer n and a 2D array requirements, where requirements[i] = [endi, cnti] represents the end index and the inversion count of each requirement.

A pair of indices (i, j) from an integer array nums is called an inversion if:

    i < j and nums[i] > nums[j]

Return the number of perm of [0, 1, 2, ..., n - 1] such that for all requirements[i], perm[0..endi] has exactly cnti inversions.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, requirements = [[2,2],[0,0]]

Output: 2

Explanation:

The two permutations are:

    [2, 0, 1]
        Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
        Prefix [2] has 0 inversions.
    [1, 2, 0]
        Prefix [1, 2, 0] has inversions (0, 2) and (1, 2).
        Prefix [1] has 0 inversions.

Example 2:

Input: n = 3, requirements = [[2,2],[1,1],[0,0]]

Output: 1

Explanation:

The only satisfying permutation is [2, 0, 1]:

    Prefix [2, 0, 1] has inversions (0, 1) and (0, 2).
    Prefix [2, 0] has an inversion (0, 1).
    Prefix [2] has 0 inversions.

Example 3:

Input: n = 2, requirements = [[0,0],[1,0]]

Output: 1

Explanation:

The only satisfying permutation is [0, 1]:

    Prefix [0] has 0 inversions.
    Prefix [0, 1] has no inversions.

 

Constraints:

    2 <= n <= 300
    1 <= requirements.length <= n
    requirements[i] = [endi, cnti]
    0 <= endi <= n - 1
    0 <= cnti <= 400
    The input is generated such that there is at least one i such that endi == n - 1.
    The input is generated such that all endi are unique.

*/

#include<iostream>
using namespace std;
#include<vector>

int merge(vector<int> &nums, int st, int end, int mid){
    int inversionCount = 0;

    vector<int> temp;
    int i = st, j = mid + 1;

    while(i <= mid && j <= end){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        } else{
            inversionCount += (mid - i + 1);
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(nums[j]);
        j++;
    }

    for(int i = 0;i < temp.size();i++){
        nums[i + st] = temp[i];
    }

    return inversionCount;
}
    
int mergeSort(vector<int> &nums, int i, int j){
    if(i >= j){
        return 0;
    }

    int mid = i + (j - i) / 2;
    int leftInversion = mergeSort(nums, i, mid);
    int rightInversion = mergeSort(nums, mid + 1, j);
    int inverCount = merge(nums, i, j, mid);

    return leftInversion + rightInversion + inverCount;
}

int countInversions(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    int n;
    cout<<"enter the size: ";
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<countInversions(arr);

}
