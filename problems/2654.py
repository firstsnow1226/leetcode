class Solution:
    def minOperations(self, nums: List[int]) -> int:
        find_one = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                find_one += 1
        if find_one:
            return len(nums)-find_one
        min_L = 100
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                num = nums[i]
                for k in range(i,j):
                    num = gcd(num,nums[k+1])
                if num == 1:
                    min_L = min(min_L,j-i+1)
        if min_L == 100:
            return -1
        else:
            return min_L+len(nums)-2
