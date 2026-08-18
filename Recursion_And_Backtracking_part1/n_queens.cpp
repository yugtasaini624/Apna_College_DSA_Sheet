/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
    1 <= n <= 9
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<string> > ans;

bool isSafe(vector<string> &board, int row, int coln, int n){
    // horizontal
    for(int i = 0;i < n;i++){
        if(board[row][i] == 'Q') return false;
    }

    // vertical
    for(int i = 0;i < n;i++){
        if(board[i][coln] == 'Q') return false;
    }

    // left diagonal
    for(int i = row, j = coln; i >= 0 && j >= 0;i--,j--){
        if(board[i][j] == 'Q') return false;
    }

    // right diagonal
    for(int i = row, j = coln; i >= 0 && j < n;i--, j++){
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void nqueens(vector<string> &board, int row, int n){
    if(row == n){
        ans.push_back(board);
        return;
    }

    for(int i = 0;i < n;i++){
        if(isSafe(board, row, i, n)){
            board[row][i] = 'Q';
            nqueens(board, row + 1, n);
            board[row][i] = '.';
        }
    }
}

int main(){
    int n;
    cout<<"Enter no. of queens: ";
    cin>>n;

    vector<string> board(n, string(n, '.'));

    nqueens(board, 0, n);
    for(int k = 0; k < ans.size(); k++){
        cout<<"Solution "<<k + 1<<": "<<endl;

        for(int i = 0; i < n; i++){
            cout<<ans[k][i]<<endl;
        }
        cout << endl;
    }
    return 0;
}