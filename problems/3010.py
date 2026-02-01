class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = nums[0]
        min1 = min(nums[1],nums[2])
        min2 = max(nums[1],nums[2])
        for i in range(3, len(nums)):
            if nums[i] < min1:
                min2 = min1
                min1 = nums[i]
            elif nums[i] < min2:
                min2 = nums[i]
        ans += min1+min2
        return ans

