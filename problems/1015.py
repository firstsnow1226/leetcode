class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        re = []
        now = 0
        cnt = 0
        while(True):
            now = now*10+1
            now %= k
            cnt += 1
            if now == 0:
                return cnt
            if now in re:
                return -1
            re.append(now)
        
