    '''
    LeetCode : 1110
    Company Tags                : Google, Amazon
    Leetcode Qn Link            : https://leetcode.com/problems/delete-nodes-and-return-forest/
    T.C :    O(N) N no of Nodes
    S.C :    O(N+M) N for hashmap and M for storing trees or answer
    '''

    # Definition for a binary tree node.
    # class TreeNode:
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution:
        def solve(self,root,delete,Forest):
            if (root==None):
                return None
            root.left=self.solve (root.left,delete,Forest)
            root.right=self.solve(root.right,delete,Forest)
    
            if (root!=None and root.val in delete ):
                if root.left:
                    Forest.append(root.left)
                if root.right:
                    Forest.append(root.right)
                return None
            return root
        def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
            Forest=[]
            h={}
            for i in range(len(to_delete)):
                if to_delete[i] in h:
                    h[to_delete[i]]+=1
                else:
                    h.setdefault(to_delete[i],1)
            root=self.solve(root,h,Forest)
            if root!=None:
                Forest.append(root)
            return Forest
