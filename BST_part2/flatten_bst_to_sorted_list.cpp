/*
🟢 LeetCode 897 — Increasing Order Search Tree

Problem:
Given the root of a Binary Search Tree, rearrange the tree so that:

The smallest node becomes the root.
Every node has no left child.
Every node has a right child pointing to the next larger node.
The result is in increasing (sorted) order.

Example:

        5
       / \
      3   6
     / \   \
    2   4   8
       /   / \
      1   7   9

becomes:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7
             \
              8
               \
                9
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        inorder(root, curr);

        return dummy->right;
    }

    void inorder(TreeNode* root, TreeNode*& curr) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, curr);

        root->left = NULL;
        curr->right = root;
        curr = root;

        inorder(root->right, curr);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution obj;

    TreeNode* ans = obj.increasingBST(root);

    // Print the flattened BST
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->right;
    }

    return 0;
}