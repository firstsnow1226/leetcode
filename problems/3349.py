class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)-2*k+1):
            find = True
            for j in range(2):
                for m in range(1,k):
                    if nums[k*j+m+i] <= nums[k*j+m-1+i]:
                        find = False
            if find:
                return True
        return False
