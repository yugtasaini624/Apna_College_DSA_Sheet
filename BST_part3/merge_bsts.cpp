/*
You are given n BST (binary search tree) root nodes for n separate BSTs stored in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two roots have the same value. In one operation, you can:

    Select two distinct indices i and j such that the value stored at one of the leaves of trees[i] is equal to the root value of trees[j].
    Replace the leaf node in trees[i] with trees[j].
    Remove trees[j] from trees.

Return the root of the resulting BST if it is possible to form a valid BST after performing n - 1 operations, or null if it is impossible to create a valid BST.

A BST (binary search tree) is a binary tree where each node satisfies the following property:

    Every node in the node's left subtree has a value strictly less than the node's value.
    Every node in the node's right subtree has a value strictly greater than the node's value.

A leaf is a node that has no children.

 

Example 1:

Input: trees = [[2,1],[3,2,5],[5,4]]
Output: [3,2,5,1,null,4]
Explanation:
In the first operation, pick i=1 and j=0, and merge trees[0] into trees[1].
Delete trees[0], so trees = [[3,2,5,1],[5,4]].

In the second operation, pick i=0 and j=1, and merge trees[1] into trees[0].
Delete trees[1], so trees = [[3,2,5,1,null,4]].

The resulting tree, shown above, is a valid BST, so return its root.

Example 2:

Input: trees = [[5,3,8],[3,2,6]]
Output: []
Explanation:
Pick i=0 and j=1 and merge trees[1] into trees[0].
Delete trees[1], so trees = [[5,3,8,2,6]].

The resulting tree is shown above. This is the only valid operation that can be performed, but the resulting tree is not a valid BST, so return null.

Example 3:

Input: trees = [[5,4],[3]]
Output: []
Explanation: It is impossible to perform any operations.

 

Constraints:

    n == trees.length
    1 <= n <= 5 * 104
    The number of nodes in each tree is in the range [1, 3].
    Each node in the input may have children but no grandchildren.
    No two roots of trees have the same value.
    All the trees in the input are valid BSTs.
    1 <= TreeNode.val <= 5 * 104.

*/

#include <bits/stdc++.h>
using namespace std;

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
    bool solve(TreeNode *root, long long leftLimit, long long rightLimit, unordered_map<int, TreeNode*>& roots, unordered_set<int>& leafNode) {
        if(root == NULL)
            return true;

        if(leftLimit >= root->val || root->val >= rightLimit)
            return false;

        if(root->left == NULL && root->right == NULL && roots.count(root->val)) {
            TreeNode *mergeRoot = roots[root->val];

            root->left = mergeRoot->left;
            root->right = mergeRoot->right;

            roots.erase(root->val);
        }

        bool left = solve(root->left, leftLimit, root->val, roots, leafNode);
        bool right = solve(root->right, root->val, rightLimit, roots, leafNode);

        return left && right;
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;
        unordered_set<int> leafNode;

        for(auto &tree : trees) {
            roots[tree->val] = tree;

            if(tree->left != NULL)
                leafNode.insert(tree->left->val);

            if(tree->right != NULL)
                leafNode.insert(tree->right->val);
        }

        TreeNode *finalRoot = NULL;

        for(auto &tree : trees) {
            if(!leafNode.count(tree->val)) {
                if(finalRoot != NULL)
                    return NULL;

                finalRoot = tree;
            }
        }

        if(finalRoot == NULL)
            return NULL;

        roots.erase(finalRoot->val);

        bool isBST = solve(finalRoot, LLONG_MIN, LLONG_MAX, roots, leafNode);

        if(!isBST || !roots.empty())
            return NULL;

        return finalRoot;
    }
};

void inorder(TreeNode* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<TreeNode*> trees;

    for(int i = 0; i < n; i++) {
        int rootVal, leftVal, rightVal;
        cin >> rootVal >> leftVal >> rightVal;

        TreeNode* root = new TreeNode(rootVal);

        if(leftVal != -1)
            root->left = new TreeNode(leftVal);

        if(rightVal != -1)
            root->right = new TreeNode(rightVal);

        trees.push_back(root);
    }

    TreeNode* result = obj.canMerge(trees);

    if(result == NULL) {
        cout << "NULL" << endl;
    }
    else {
        cout << "Merged BST (Inorder): ";
        inorder(result);
        cout << endl;
    }

    return 0;
}