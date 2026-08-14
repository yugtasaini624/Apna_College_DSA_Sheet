/*
In an array, , the elements at indices and (where ) form an inversion if . In other words, inverted elements and are considered to be "out of order". To correct an inversion, we can swap adjacent elements.
Example
To sort the array, we must perform the following two swaps to correct the inversions:
The sort has two inversions: and .
Given an array , return the number of inversions to sort the array.

Complete the function countInversions in the editor below.
countInversions has the following parameter(s):
    int arr[n]: an array of integers to sort
Returns
    int: the number of inversions

Sample Input

STDIN       Function
-----       --------
2           d = 2
5           arr[] size n = 5 for the first dataset
1 1 1 2 2   arr = [1, 1, 1, 2, 2]
5           arr[] size n = 5 for the second dataset     
2 1 3 1 2   arr = [2, 1, 3, 1, 2]

Sample Output
0  
4   

Explanation
We sort the following datasets:
    is already sorted, so there are no inversions for us to correct.
*/

#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &arr, int i, int j, int mid){
    vector<int> vec;

    int left = i;
    int right = mid + 1;


    int count = 0;

    while(left <= mid && right <= j){
        if(arr[left] < arr[right]){
            vec.push_back(arr[left]);
            left++;
        } else{
            vec.push_back(arr[right]);
            count++;
            right++;
        }
    }

    while(left <= mid){
        vec.push_back(arr[left]);
        left++;
    }

    while(right <= j){
        vec.push_back(arr[right]);
        right++;
    }

    for(int k = i;k <= j;k++){
        arr[k] = vec[k - 1];
    }

    return count;
}

int mergeSort(vector<int> &arr, int i, int j){
    if(i >= j) return 0;

    int mid = i + (j - i) / 2;

    int left = mergeSort(arr, i, mid);
    int right = mergeSort(arr, mid + 1, j);

    int curr = merge(arr, i, j, mid);

    return left + curr + right;
}

int countInversion(vector<int> &arr){
    int n = arr.size();

    return mergeSort(arr, 0, n - 1);
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }

    cout<<countInversion(arr);
}