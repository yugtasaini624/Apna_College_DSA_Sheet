/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100

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
    bool helper(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;

        return root1->val == root2->val && helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return helper(root->left, root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if(obj.isSymmetric(root))
        cout<<"Tree is Symmetric";
    else
        cout<<"Tree is Not Symmetric";

    return 0;
}