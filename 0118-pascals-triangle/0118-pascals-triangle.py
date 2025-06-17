class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = [ [1] * (i+1) for i in range(numRows)]
        for i in range(2,numRows):
            for j in range(i):
                if j==0 or j==i:
                    continue
                res[i][j] = res[i-1][j-1]+ res[i-1][j]
        
        return res