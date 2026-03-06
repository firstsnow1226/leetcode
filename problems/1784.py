class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        now = '0'
        cnt = 0
        for ch in s:
            if now == '0' and ch =='1':
                cnt += 1
                now = '1'
            else:
                now = ch
        if cnt <= 1:
            return True
        return False
