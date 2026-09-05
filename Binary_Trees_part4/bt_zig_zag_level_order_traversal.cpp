/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>levels;
        levels.push(root);
        int levelCnt = 0;

        while(!levels.empty()){
            int levelSize = levels.size();
            vector<int>currLevel;

            for(int i = 0 ; i < levelSize ; i++){
                TreeNode* curr = levels.front();
                currLevel.push_back(curr->val);
                levels.pop();

                if(curr->left) levels.push(curr->left);
                if(curr->right) levels.push(curr->right);
            }
            if(levelCnt % 2 == 1 ) {
                reverse(currLevel.begin(),currLevel.end());
                ans.push_back(currLevel);
            }
            else  ans.push_back(currLevel);

            levelCnt++;
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal:" << endl;

    for(auto level : ans) {
        cout << "[ ";

        for(int val : level) {
            cout << val << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}