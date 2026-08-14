/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int> > &arr){
    int row = arr.size();
    int coln = arr[0].size();

    vector<int> ans;

    int top = 0, bottom = row - 1, left = 0, right = coln - 1;

    while(top <= bottom && left <= right){
        for(int i = left;i <= right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        for(int i = top;i <= bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i = right;i >= left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom;i >= top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main(){
    int row, coln;
    cout<<"Enter row and coln: ";
    cin>>row>>coln;

    vector<vector<int> > arr(row, vector<int> (coln));

    cout<<"Enter the values: "<<endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < coln;j++){
            cin>>arr[i][j];
        }
    }

    vector<int> res = spiralMatrix(arr);

    cout<<"New result = ";
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<" ";
    }
}