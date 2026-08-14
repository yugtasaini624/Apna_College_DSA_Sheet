/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -231 <= matrix[i][j] <= 231 - 1
*/

#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int> >& arr) {
    int row = arr.size();
    int coln = arr[0].size();

    bool firstRow = false, firstColn = false;

    // step 1: check first row and first coln
    for(int i = 0;i < coln;i++){
        if(arr[0][i] == 0){
            firstRow = true;
            break;
        }
    }

    for(int i = 0;i < row;i++){
        if(arr[i][0] == 0){
            firstColn = true;
            break;
        }
    }

    // step 2: mark borders 0 if inner matrix contain zero
    for(int i = 1;i < row;i++){
        for(int j = 1;j < coln;j++){
            if(arr[i][j] == 0){
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }

    // step 3: now after updating the borders with 0 make the inner matrix correct by making 0 where required
    for(int i = 1;i < row;i++){
        for(int j = 1;j < coln;j++){
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    // step 4: make the first row and first coln zero if it contain any zero
    if(firstRow){
        for(int i = 0;i < coln;i++){
            arr[0][i] = 0;
        }
    }

    if(firstColn){
        for(int i = 0;i < row;i++){
            arr[i][0] = 0;
        }
    }

    return;
}

int main(){
    int row, coln;
    cout<<"Enter row and coln: ";
    cin>>row>>coln;

    vector<vector<int> > arr(row, vector<int>(coln));

    cout<<"Enter the element: "<<endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < coln;j++){
            cin>>arr[i][j];
        }
    }

    setZeroes(arr);

    cout<<"Updated array : "<<endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < coln;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}