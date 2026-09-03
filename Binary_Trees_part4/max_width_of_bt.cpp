/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:

Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).

 

Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100

*/

#include<bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        long long res = 1;
        queue<pair<TreeNode*, long long>> q;
        
        q.push({root, 0});      
        
        while(!q.empty()){
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i < cnt; ++i){
                pair<TreeNode*, int> p = q.front();
                long long idx = p.second - start;
                
                q.pop();
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution obj;

    cout<<"Maximum width of binary tree: "<<obj.widthOfBinaryTree(root);

    return 0;
}