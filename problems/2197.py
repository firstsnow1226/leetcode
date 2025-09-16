class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        ans = []
        
        for num in nums:
            tmp = num
            while len(ans) > 0:
                last = ans[-1]
                if math.gcd(last,tmp) == 1:
                    break
                tmp = math.lcm(last,tmp)
                ans.pop()
            ans.append(tmp)
        return ans
