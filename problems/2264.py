class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans = -1
        now = 'a'
        cnt = 0
        for x in num:
            if x == now:
                cnt += 1
            else:
                now = x
                cnt = 1
            if cnt >= 3:
                ans = max(ans,int(x))
        
        return ("" if ans == -1 else str(ans)+str(ans)+str(ans))
        
