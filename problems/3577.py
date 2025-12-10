MOD = 1000000007
class Solution:
    def countPermutations(self, complexity: List[int]) -> int:
        zero = complexity[0]
        ans = 1
        for i in range(1,len(complexity)):
            if complexity[i] <= zero:
                return 0
            ans *= i
            ans %= MOD
        return ans
        
