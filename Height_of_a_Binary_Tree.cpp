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
    int solveBFS(TreeNode*root){
        int lv=0;
        queue<TreeNode*>q;
        q.push(root);
        

        while(!q.empty()){
            
            int n=q.size();
            
            
            while(n--){
                TreeNode*nd=q.front();
                q.pop();
                if(nd->left)q.push(nd->left);
                if(nd->right)q.push(nd->right);

                
            }
            lv++;
            
        }
        return lv;
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return solveBFS(root);
    }
};
