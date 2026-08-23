/*
Problem Statement
Suppose there are n people at a party, labeled from 0 to n - 1.A celebrity is a person who satisfies both conditions:

Everyone else knows the celebrity.
The celebrity knows nobody else.

You are given an API:

bool knows(int a, int b);

It returns true if person a knows person b.

Your task is to find the celebrity. If there is no celebrity, return -1.

The goal is to use as few calls to knows() as possible.

Example
Input:
graph = [
    [1,1,0],
    [0,1,0],
    [1,1,1]
]

Output:
1

Explanation:

Person 0 knows 1
Person 2 knows 1
Person 1 knows nobody else

Therefore, person 1 is the celebrity
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& graph, int n) {
        int candidate = 0;

        for(int i = 1; i < n; i++) {
            if(graph[candidate][i] == 1) {
                candidate = i;
            }
        }

        for(int i = 0; i < n; i++) {

            if(i == candidate)
                continue;

            if(graph[candidate][i] == 1 ||
               graph[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0}
    };

    int n = graph.size();

    int ans = obj.celebrity(graph, n);

    if(ans == -1)
        cout<<"No Celebrity"<<endl;
    else
        cout<<"Celebrity: "<<ans<<endl;

    return 0;
}