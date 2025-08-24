class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        prev = 0
        num = 0
        zero_num = 0
        connect = False
        ans = 0
        for x in nums:
            if x == 0:
                if zero_num == 0:
                    prev = num
                    num = 0
                zero_num += 1
            else:
                if num == 0:
                    connect = False
                    if zero_num <= 1:
                        connect = True
                    zero_num = 0
                num += 1
                ans = max(ans, (prev+num if connect else num))
        return (ans-1 if ans == len(nums) else ans)
                    
                
            
