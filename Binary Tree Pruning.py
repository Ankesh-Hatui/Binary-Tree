'''
L.C : 814
LINK: https://leetcode.com/problems/binary-tree-pruning/description/
T.C : O(N)
S.C: O(N) for recursive stack
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root):
        if (root==None):
            return None
        root.left=self.solve(root.left)
        root.right=self.solve(root.right)
        if (root.val==0 and not root.left and not root.right):
            return None
        return root
        
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.solve(root)
