INF = 1000000005
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        
        preN = 0
        pre = -INF
        nowN = 1
        now = nums[0]
        ans = 0
        for i in range(1,len(nums)):
            if nums[i] == now :
                nowN += 1
            else:
                preN = nowN
                pre = now
                nowN = 1
                now = nums[i]

            #print(pre, preN, now, nowN)
            if now == pre + 1:
                ans = max(ans,nowN+preN)
        return ans





