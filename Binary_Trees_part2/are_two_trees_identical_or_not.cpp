/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104

*/

#include<iostream>
#include<vector>
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
    void preorder(TreeNode *root, vector<int> &arr){
        if(root == nullptr){
            arr.push_back(INT_MIN);
            return;
        }

        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> arr1;
        vector<int> arr2;

        preorder(p, arr1);
        preorder(q, arr2);

        if(arr1.size() != arr2.size()) return false;

        for(int i = 0;i < arr1.size();i++){
            if(arr1[i] != arr2[i]) return false;
        }

        return true;
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if (obj.isSameTree(p, q))
        cout<<"Same Tree";
    else
        cout<<"Different Tree";

    return 0;
}