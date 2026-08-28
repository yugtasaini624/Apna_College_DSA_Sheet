/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself. 

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false

 
Constraints:

    The number of nodes in the root tree is in the range [1, 2000].
    The number of nodes in the subRoot tree is in the range [1, 1000].
    -104 <= root.val <= 104
    -104 <= subRoot.val <= 104

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
    bool isSame(TreeNode* root,TreeNode* subRoot){
        if(subRoot!=nullptr&&root!=nullptr){
            if(root->val==subRoot->val){
                return isSame(root->left,subRoot->left)&&isSame(root->right,subRoot->right);
            }
            return false;
        }
        if(subRoot==root){
            return true;
        }
        else{return false;}
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root!=nullptr){
            if(root->val==subRoot->val){
                if(isSame(root,subRoot)){
                    return true;
                }
            }
            return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        }
        return false;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution obj;

    if (obj.isSubtree(root, subRoot)) {
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
}
