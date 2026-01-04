class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            cnt = 0
            tot = 0
            for x in range(1, floor(sqrt(num))+1 ):
                if x*x == num:
                    cnt = -1
                    break
                if num % x == 0:
                    cnt += 2
                    tot += x + num//x
            if cnt == 4:
                ans += tot
        return ans

