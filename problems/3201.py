class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        odd_cnt = 0
        even_cnt = 0
        cnt = 1
        now = nums[0]
        if nums[0]%2 == 0:
            even_cnt += 1
        else:
            odd_cnt += 1

        for i in range(1,len(nums)):
            if ( nums[i] + now ) % 2 == 1:
                now = nums[i]
                cnt += 1
            
            if nums[i]%2 == 0:
                even_cnt += 1
            else:
                odd_cnt += 1

        return max(max(odd_cnt,even_cnt),cnt)

        
