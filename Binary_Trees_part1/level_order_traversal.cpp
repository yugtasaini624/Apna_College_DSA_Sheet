/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000

*/

#include<iostream>
#include<vector>
#include<queue>
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
    void bfs(TreeNode* root, vector<vector<int>> &ans){
        if(root == nullptr) return;

        queue<TreeNode *> q;
        vector<int> vec;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0;i < size;i++){
                TreeNode *temp = q.front();
                vec.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                q.pop();
            }
            ans.push_back(vec);
            vec.clear();
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};

int main(){
     TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.levelOrder(root);

    cout<<"Level Order Traversal:"<<endl;

    for(auto level : ans) {
        for(int x : level) {
            cout<<x<<" ";
        }
    }

    return 0;
}