/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/

#include<iostream>
#include<vector>
using namespace std;

// soln 1 TC -> O(n) & SC -> O(n)
int maxWater(vector<int> &arr){
    int n = arr.size();

    vector<int> left(n, 0);
    left[0] = arr[0];

    vector<int> right(n , 0);
    right[n - 1] = arr[n - 1];

    for(int i = 1;i < n;i++){
        left[i] = max(arr[i], left[i - 1]);
    }

    for(int i = n - 2;i >= 0;i--){
        right[i] = max(right[i + 1], arr[i]);
    }

    int maxWater = 0;

    for(int i = 0;i < n;i++){
        maxWater += min(left[i], right[i]) - arr[i];
    }

    return maxWater;
}

// soln 2 TC -> O(n) & SC -> O(1)
int maxWaterII(vector<int> &arr){
    int n = arr.size();

    int left = 0, right = 0;
    int maxWater = 0;

    int i = 0, j = n - 1;
    while(i < j){
        left = max(left, arr[i]);
        right = max(right, arr[j]);

        if(left < right){
            maxWater += left - arr[i];
            i++;
        } else{
            maxWater += right - arr[j];
            j--;
        }
    }

    return maxWater;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<"Max Water = "<<maxWaterII(arr);
}