class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = 0
        conti = [1]
        for i in range(1,len(nums)):
            if nums[i] > nums[i-1]:
                conti.append(conti[i-1]+1)
            else:
                conti.append(1)
            if i-conti[i] >= 0:
                ans = max(ans,min(conti[i],conti[i-conti[i]]))
            ans = max(ans,conti[i]//2)
        #print(conti)
        return ans
