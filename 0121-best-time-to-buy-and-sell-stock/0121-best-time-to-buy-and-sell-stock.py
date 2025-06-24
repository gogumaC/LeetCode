class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min=0
        max=0
        max_profit=0
        for i in range(1,len(prices)):
            if prices[min]>prices[i]:
                min=i
                max=i
                continue
            profit = prices[i]-prices[min]
            if profit>max_profit:
                max = i
                max_profit = profit
            
        return max_profit

        