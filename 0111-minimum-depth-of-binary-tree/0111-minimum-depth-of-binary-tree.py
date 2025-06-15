# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution(object):

    def minDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if(not root):
            return 0
        q = deque()
        q.append((root,1))
        while(q):
            n,d=q.popleft()
            if(not n.left and not n.right):
                return d
            children = [c for c in (n.left,n.right) if c is not None]

            for c in children:
                if(not c.left and not c.right):
                    return d+1
                else:
                    q.append((c,d+1))
        
        return 0


        