from collections import defaultdict

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        l = defaultdict(int)

        for n in nums:
            l[n]+=1

        res = [x for x,n in l.items() if n%2!=0]
        return res[0]
        