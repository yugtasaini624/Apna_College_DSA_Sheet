/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

    TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
    int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.

 

Example 1:

Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor

 

Constraints:

    1 <= k <= n <= 5 * 104
    parent.length == n
    parent[0] == -1
    0 <= parent[i] < n for all 0 < i < n
    0 <= node < n
    There will be at most 5 * 104 queries.

*/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeAncestor {
public:
    vector<vector<int>>v;
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> par(n, vector<int>(20));
        for (int i = 0; i < n; i++) par[i][0] = parent[i];
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                if (par[i][j - 1] == -1) par[i][j] = -1;
                else par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
        swap(v, par);
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

int main() {
    int n = 7;

    vector<int> parent = {
        -1,  // parent of 0
         0,  // parent of 1
         0,  // parent of 2
         1,  // parent of 3
         1,  // parent of 4
         2,  // parent of 5
         3   // parent of 6
    };

    TreeAncestor* obj = new TreeAncestor(n, parent);

    // Test cases
    cout << "2nd ancestor of node 6: "
         << obj->getKthAncestor(6, 2) << endl;

    cout << "1st ancestor of node 6: "
         << obj->getKthAncestor(6, 1) << endl;

    cout << "3rd ancestor of node 6: "
         << obj->getKthAncestor(6, 3) << endl;

    cout << "4th ancestor of node 6: "
         << obj->getKthAncestor(6, 4) << endl;

    delete obj;

    return 0;
}
