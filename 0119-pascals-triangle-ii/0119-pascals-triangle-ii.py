class Solution(object):
    def getRow(self, rowIndex):

        list=[1]
        list = [1]*(rowIndex+1)
        
        for i in range(2,rowIndex+1):
            tmp = list[:]
            for j in range(1,i):
                
                list[j] = tmp[j-1]+tmp[j]



        return list[:rowIndex+1] 
            
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        