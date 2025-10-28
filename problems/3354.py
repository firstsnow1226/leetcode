class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        prsL = [0]*(n+2)
        prsR = [0]*(n+2)

        for i in range(1,n+1):
            prsL[i] = prsL[i-1] + nums[i-1]
            prsR[n+1-i] = prsR[n+2-i] + nums[n-i]
        ans = 0
        for i in range(1,n+1):
            if nums[i-1] != 0:
                continue
            
            if prsL[i] == prsR[i]:
                ans += 2
            elif abs(prsL[i]-prsR[i]) == 1:
                ans += 1
            
        return ans


