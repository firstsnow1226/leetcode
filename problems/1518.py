class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange :
            cnt = numBottles // numExchange
            ans += cnt
            numBottles -= cnt*(numExchange-1)
        
        return ans
        
