/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

 

Constraints:

    The number of nodes in the tree is in the range [2, 1000].
    -231 <= Node.val <= 231 - 1

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        helper(root);

        // Swap the values of the two wrong nodes
        swap(first->val, second->val);
    }

    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;

        helper(node->right);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery: ";
    inorder(root);

    Solution obj;
    obj.recoverTree(root);

    cout << "\nAfter recovery: ";
    inorder(root);

    return 0;
}