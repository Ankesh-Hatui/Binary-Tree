/*
* Leetcode : 652
* T.C : O(N^2)
* S.C : O(N)+O(N)
*/

*Brute Force*:

class Solution {
    void DFS(TreeNode*root,string& curr){
        if (root==NULL){
            curr+="NULL";
            curr+=",";
            return;
        }
        
        DFS(root->left,curr);
        DFS(root->right,curr);
        curr+=to_string(root->val);
        curr+=",";
    }
    void check(TreeNode *root,unordered_map<string,int>&mp,vector<TreeNode*>&ans){
        if (root==NULL){
            return;
        }
        string s="";
        DFS(root,s);
        if (mp[s]>0 ){
            ans.push_back(root);
            mp[s]=-1;
        }
        else if (mp[s] !=-1)
        {
            mp[s]+=1;
        }
        check(root->left,mp,ans);
        check(root->right,mp,ans);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>ans;
        check(root,mp,ans);
        return ans;
    }
};
