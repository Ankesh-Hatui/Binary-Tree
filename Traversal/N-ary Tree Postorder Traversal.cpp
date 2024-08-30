// Leetcode no: 590
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void solve(Node *root,vector<int>&ans){
        if(root==nullptr)return;
        int t=root->val;
        for(auto it:root->children){
            solve(it,ans);
        }
        ans.push_back(t);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};
