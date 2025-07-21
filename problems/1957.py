class Solution:
    def makeFancyString(self, s: str) -> str:
        ans = ""

        cnt = 0
        now = 'A'

        for ch in s:
            if ch == now and cnt == 2:
                continue
            if ch == now:
                cnt += 1
            else:
                cnt = 1
                now = ch
            ans += ch
        return ans

            
                
