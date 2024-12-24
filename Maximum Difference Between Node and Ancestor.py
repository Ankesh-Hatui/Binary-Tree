'''
Leetcode : https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
Leetcode No: 1026
T.C: O(N) N is no of Node
S.C: O(h) is the height of Tree due to recursion stack
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DFS(self,root,mini,maxi,result):
        if (root==None):
            result['maxi']=max(result['maxi'],maxi-mini)
            return
        mini=min(mini,root.val)
        maxi=max(maxi,root.val)
        self.DFS(root.left,mini,maxi,result)
        self.DFS(root.right,mini,maxi,result)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        result={'maxi':0}
        self.DFS(root,float('inf'),-float('inf'),result)
        return result['maxi']
