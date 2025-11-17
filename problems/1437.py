class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        cnt = 100005
        for num in nums:
            if num == 1:
                if cnt < k:
                    return False
                cnt = 0
            else:
                cnt += 1
        return True
        
