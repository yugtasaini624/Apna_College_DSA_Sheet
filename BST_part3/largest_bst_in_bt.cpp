/*
LeetCode 333 — Largest BST Subtree

Problem Statement:
Given the root of a binary tree, return the size of the largest subtree that is also a Binary Search Tree (BST).

A BST is a binary tree where:

All values in the left subtree are less than the root's value.
All values in the right subtree are greater than the root's value.
Both left and right subtrees must also be BSTs.

Return the number of nodes in the largest BST subtree.
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
    int ans = 0;

    vector<int> solve(TreeNode* root) {
        if(root == nullptr)
            return {1, 0, INT_MAX, INT_MIN};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        if(left[0] && right[0] &&
           root->val > left[3] && root->val < right[2]) {

            int size = left[1] + right[1] + 1;
            ans = max(ans, size);

            int mn = min(root->val, left[2]);
            int mx = max(root->val, right[3]);

            return {1, size, mn, mx};
        }

        return {0, 0, 0, 0};
    }

    int largestBSTSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);

    root->right->right = new TreeNode(7);

    Solution obj;

    cout << obj.largestBSTSubtree(root) << endl;

    return 0;
}