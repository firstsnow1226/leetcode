class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        cnt = 0
        for num in nums:
            cnt *= 2
            cnt += num
            cnt %= 5
            if cnt == 0:
                ans.append(True)
            else:
                ans.append(False)
        return ans
        
