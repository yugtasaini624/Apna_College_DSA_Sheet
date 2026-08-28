/*
Given a binary tree, determine if it is .

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true


Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -104 <= Node.val <= 104

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
public:
    int dfsHeight(TreeNode *root){
        if(!root) return 0;

        int leftHeight = dfsHeight(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root)) {
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
}
