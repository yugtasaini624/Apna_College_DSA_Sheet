
#include<iostream>
#include<vector>
using namespace std;

vector<string> ans;

void helper(vector<vector<int>> &maze, int row, int coln, string &curr){
    if(row < 0 || row >= maze.size() || coln < 0 || coln >= maze.size() || maze[row][coln] == 0){
        return;
    }
        
    if(row == maze.size() - 1 && coln == maze.size() - 1){
        ans.push_back(curr);
        return;
    }
        
    maze[row][coln] = 0;
        
    curr += 'D';
    helper(maze, row + 1, coln, curr);
    curr.pop_back();
        
    curr += 'L';
    helper(maze, row, coln - 1, curr);
    curr.pop_back();
        
    curr += 'R';
    helper(maze, row, coln + 1, curr);
    curr.pop_back();
        
    curr += 'U';
    helper(maze, row - 1, coln, curr);
    curr.pop_back();
        
    maze[row][coln] = 1;
        
}
    
vector<string> ratInMaze(vector<vector<int>>& maze) {
    string curr = "";
    helper(maze, 0, 0, curr);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of maze: ";
    cin>>n;

    vector<vector<int> > maze(n, vector<int> (n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>maze[i][j];
        }
    }

    cout<<"Paths are:"<<endl;
    vector<string> paths = ratInMaze(maze);
    for(int i = 0;i < paths.size();i++){
        cout<<paths[i]<<endl;
    }
}