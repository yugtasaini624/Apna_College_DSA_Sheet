/*
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3

Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.

Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int node, vector<int>& color, vector<vector<int>>& graph, int c){
    for(int neighbor : graph[node]) {
        if(color[neighbor] == c)
            return false;
    }
    return true;
}

bool solve(int node, int v, int m, vector<int> &colors, vector<vector<int> > &graph){
    if(node == v){
        return true;
    }

    for(int i = 1;i <= m;i++){
        if(isSafe(node, colors, graph, i)){
            colors[node] = i;

            if(solve(node + 1, v, m, colors, graph)){
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(int v, vector<vector<int> > &edges, int m){
    vector<vector<int> > graph(v);

    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colors(m);

    return solve(0, v, m, colors, graph);
}

int main(){
    int V, E, m;
    cin>>V>>E>>m;

    vector<vector<int> > edges(E, vector<int>(2));

    for(int i = 0; i < E; i++) {
        cin>>edges[i][0]>>edges[i][1];
    }

    if(graphColoring(V, edges, m))
        cout<<"true\n";
    else
        cout<<"false\n";

    return 0;
}