/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/

#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> arr;

    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            arr.push_back(nums1[i]);
            i++;
        } else{
            arr.push_back(nums2[j]);
            j++;
        }
    }

    while(i < n1) arr.push_back(nums1[i++]);
    while(j < n2) arr.push_back(nums2[j++]);

    int n = arr.size();
    if(n % 2 != 0){
        return (double)arr[n / 2];
    } else{
        double ans = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        return ans;
    }

    return 0.0;
}

int main(){
    int n1, n2;
    cout<<"Enter two vals: ";
    cin>>n1>>n2;

    cout<<"Enter vals in array 1: ";
    vector<int> arr1(n1);
    for(int i = 0;i < n1;i++){
        cin>>arr1[i];
    }

    cout<<"Enter vals in array 2: ";
    vector<int> arr2(n2);
    for(int i = 0;i < n2;i++){
        cin>>arr2[i];
    }

    cout<<"Median = "<<findMedianSortedArrays(arr1, arr2);
}