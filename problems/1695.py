class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        cnt = [0]*10005

        L = -1
        ans = 0
        now = 0

        for num in nums:
            while cnt[num] != 0:
                L += 1
                now -= nums[L]
                cnt[ nums[L] ] = 0
            cnt[num] += 1
            now += num
            ans = max(ans,now)
        return ans
        
