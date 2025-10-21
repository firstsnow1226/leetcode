MAXN = 200005
class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        diff = [0]*MAXN
        cnt = [0]*MAXN
        end_p = 0
        for num in nums:
            cnt[num] += 1
            diff[ max(0,num-k) ] += 1
            diff[ num+k+1 ] -= 1
            end_p = max(end_p,num+k+1)
        ans = 0
        tot = 0
        for i in range(end_p+1):
            tot += diff[i]
            ans = max(ans,cnt[i]+min(tot-cnt[i],numOperations))
        return ans

