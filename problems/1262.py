class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        INF = 1000000
        nums.sort()
        one1 = INF
        one2 = INF
        two1 = INF
        two2 = INF
        ans = 0
        for num in nums:
            ans += num
            if num % 3 == 1:
                if one1 == INF:
                    one1 = num
                elif one2 == INF:
                    one2 = num + one1
            if num % 3 == 2:
                if two1 == INF:
                    two1 = num
                elif two2 == INF:
                    two2 = num + two1
        if ans % 3 == 0:
            return ans
        if ans % 3 == 1:
            return max(ans-one1,ans-two2)
        return max(ans-two1,ans-one2) 
