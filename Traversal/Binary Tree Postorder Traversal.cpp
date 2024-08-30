// Leetcode No: 145
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void postorder(TreeNode*root,vector<int>&ans){
        if(root==nullptr){
            return;
        }
        int t;
        t=root->val;
        if(root->left)postorder(root->left,ans);
        if(root->right)postorder(root->right,ans);
        ans.push_back(t);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
