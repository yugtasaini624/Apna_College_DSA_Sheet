/*
You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/

#include<iostream>
#include<vector>
using namespace std;

bool findElement(vector<vector<int> >& matrix, int target, int row){
    int left = 0, right = matrix[0].size() - 1;

    while(left <= right){
        int mid = left + (right - left ) / 2;

        if(matrix[row][mid] == target){
            return true;
        } else if(matrix[row][mid] > target){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int row = matrix.size();
    int coln = matrix[0].size();

    if(row == 1 && coln == 1){
        if(matrix[0][0] == target) return true;
        else return false;
    }

    int i = 0, j = row - 1;

    while(i <= j){
        int mid = i + (j - i) / 2;

        if(matrix[mid][0] <= target && matrix[mid][coln - 1] >= target){
            return findElement(matrix, target, mid);
        } else if(matrix[mid][0] > target){
            j = mid - 1;
        } else if(matrix[mid][0] < target){
            i = mid + 1;
        }
    }
    return false;
}

int main(){
    int m, n, target;
    cout<<"Enter size and target Value: ";
    cin>>m>>n>>target;

    vector<vector<int> > arr(m, vector<int> (n));
    cout<<"Enter elements in array: ";
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>arr[i][j];
        }
    }


    cout<<"Element found: "<<searchMatrix(arr, target);
    return 0;
}