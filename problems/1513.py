MOD = 1000000007
class Solution:
    def numSub(self, s: str) -> int:
        ans = 0
        cnt = 0
        for ch in s:
            if ch == '1':
                cnt += 1
            else:
                ans += cnt*(cnt+1)//2
                ans %= MOD
                cnt = 0
        ans += cnt*(cnt+1)//2
        ans %= MOD
        return ans
