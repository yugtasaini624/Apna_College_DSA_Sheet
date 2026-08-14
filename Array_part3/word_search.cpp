/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool dfs(vector<vector<char> > &board, string &word, int i, int j, int k){
    int row = board.size();
    int coln = board[0].size();

    if(k == word.length()) return true;

    if(i < 0 || i >= row || j < 0 || j >= coln || board[i][j] != word[k]) return false;

    char curr = board[i][j];
    board[i][j] = '\0';

    if(dfs(board, word, i + 1, j, k + 1) ||
        dfs(board, word, i - 1, j, k + 1) ||
        dfs(board, word, i, j + 1, k + 1) ||
        dfs(board, word, i, j - 1, k + 1))  return true;

    board[i][j] = curr;

    return false;
} 

bool exist(vector<vector<char> >& board, string word) {
    int row = board.size();
    int coln = board[0].size();

    for(int i = 0;i < row;i++){
        for(int j = 0;j < coln;j++){
            if(dfs(board, word, i, j, 0)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int row, coln;
    cout<<"Enter row and coln: ";
    cin>>row>>coln;

    string word;
    cout<<"Enter the string to find: ";
    cin>>word;

    vector<vector<char> > arr(row, vector<char>(coln));

    cout<<"Enter the element: "<<endl;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < coln;j++){
            cin>>arr[i][j];
        }
    }

    cout<<exist(arr, word);
}