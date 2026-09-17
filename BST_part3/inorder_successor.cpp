/*
Problem Statement

Given the root of a Binary Search Tree (BST) and a node p, find the inorder successor of p.

The inorder successor is the node that comes immediately after p in inorder traversal.

If no successor exists, return NULL.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;

        while(root) {
            if(root->val > p->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return successor;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left->right;

    Solution obj;

    TreeNode* ans = obj.inorderSuccessor(root, p);

    if(ans)
        cout << "Inorder Successor: " << ans->val << endl;
    else
        cout << "No Inorder Successor" << endl;

    return 0;
}