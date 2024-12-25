'''
* Leetcode : 1339
* T.C : O(N) DFS
* S.C : O(h) auxillary space
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DFS(self,root,result):
        if (root==None):
            return
        result['sum']+=root.val
        self.DFS(root.left,result)
        self.DFS(root.right,result)
    def subtree(self,root,result,curr):
        if (root==None):
            return 0
        l,r=0,0
        l=self.subtree(root.left,result,curr)
        r=self.subtree(root.right,result,curr)

        stree=l+r+root.val
        if (result['sum']-stree)*stree>result['product']:
            result['product']=(result['sum']-stree)*stree

        return stree

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        result={'sum':0,'product':0}
        self.DFS(root,result);
        # return result['sum']
        self.subtree(root,result,0)
        return result['product']%1000000007
