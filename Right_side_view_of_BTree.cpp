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
    /*
    void solveBFS(TreeNode *root,vector<int>&ans){
        if(root==nullptr){
            return;
        }
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(i==n){
                    ans.push_back(node->val);
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
        }
    }
    */
    void solveDFS(TreeNode *root,int level,vector<int>&ans){
        if(!root){
            return;
        }

        if(ans.size()<level){
            ans.push_back(root->val);
            
        }
        solveDFS(root->right,level+1,ans);
        solveDFS(root->left,level+1,ans);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>level;
        vector<int>ans;
        // solveBFS(root,ans);
        solveDFS(root,1,ans);
        return ans;
    }
};
