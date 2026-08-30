/*
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Note:

    Return the nodes from the leftmost node to the rightmost node.
    If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 

Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mp;

        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (mp.find(hd) == mp.end()) {
                mp[hd] = curr->data;
            }

            if (curr->left)
                q.push({curr->left, hd - 1});

            if (curr->right)
                q.push({curr->right, hd + 1});
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){

}
