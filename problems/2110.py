class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = 0
        cnt = 1
        pre = -1
        for p in prices:
            if p == pre-1:
                cnt += 1
            else:
                cnt = 1
            ans += cnt
            pre = p
        return ans
