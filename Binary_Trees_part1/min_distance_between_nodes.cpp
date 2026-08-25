/*
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 105

*/

#include<iostream>
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
    int minDiff = INT_MAX;
    int prev = 0;
    bool hasPrev = false;
public:
    void helper(TreeNode *root){
        if(root == nullptr) return;

        helper(root->left);

        if(hasPrev){
            minDiff = min(minDiff, abs(prev - root->val));
        }

        prev = root->val;
        hasPrev = true;
        helper(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        helper(root);
        return minDiff;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    cout <<"Minimum Difference: "<<obj.minDiffInBST(root)<<endl;

    return 0;
}