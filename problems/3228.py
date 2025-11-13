class Solution:
    def maxOperations(self, s: str) -> int:
        ans = 0
        base = 0
        new = True
        for i in range(len(s)-1,-1,-1):
            if s[i] == '1':
                ans += base
                new = True
            elif s[i] == '0' and new:
                base += 1
                new = False
        return ans
        
