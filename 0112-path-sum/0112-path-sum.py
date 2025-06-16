# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: bool
        """
        if not root:
            return False
        

        q=deque()
        q.append((root,root.val))
        while (q):
            current,total = q.pop()
            if not current.left and not current.right and total==targetSum:
                return True
            
            if current.left:
                q.append((current.left, total+current.left.val))
            if current.right:
                q.append((current.right, total+current.right.val))
            
        return False
                
        
        