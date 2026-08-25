/*
You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    void bfs(vector<vector<int> > &grid, queue<pair<int, int> > &q, int &fresh, int &min){
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            while(size--){
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(auto dir: directions){
                    int dx = dir.first;
                    int dy = dir.second;

                    int nx = x + dx;
                    int ny = y + dy;

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;
        }
    }

    int orange_rotting(vector<vector<int> > &grid){
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0, min = 0;
        
        queue<pair<int, int> > q;
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2){
                    q.push({i, j}); 
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        if(q.empty()) return -1;

        bfs(grid, q, fresh, min);

        if(fresh > 0) return -1;

        return min;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int ans = obj.orange_rotting(grid);

    cout<<"Minimum minutes: "<<ans<<endl;

    return 0;
}