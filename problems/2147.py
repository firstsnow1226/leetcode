class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 1000000007
        ans = 1
        chairs = 0
        plants = 0

        for x in corridor:
            if x == 'S':
                if chairs < 2:
                    chairs += 1
                else:
                    ans *= (plants+1)
                    ans %= MOD
                    plants = 0
                    chairs = 1
            else:
                if chairs == 2:
                    plants += 1
        
        if chairs != 2:
            return 0
        else:
            return ans


