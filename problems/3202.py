MAXN = 1000
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        
        for i in range(k):
            cnt = [0]*k

            for num in nums:
                cnt[ num % k ] = cnt[ (i+k - num%k)%k ] + 1
                #print(cnt)
            
            for x in cnt:
                ans = max(ans,x)
        return ans
            
        
