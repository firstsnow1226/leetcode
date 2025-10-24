class Solution:
    def check(self, n):
        cnt = [0]*10
        while n > 0:
            cnt[n%10] += 1
            n //= 10
        for i in range(10):
            if i == 0 and cnt[i] != 0:
                return False
            if cnt[i] == 0:
                continue
            if cnt[i] != i:
                return False
        return True
    def nextBeautifulNumber(self, n: int) -> int:
        for i in range(n+1,1224445):
            if self.check(i):
                return i
