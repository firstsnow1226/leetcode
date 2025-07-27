class Solution:
    def climbStairs(self, n: int) -> int:
        steps = [0]*50
        steps[0] = 1
        steps[1] = 1

        for i in range(2,50):
            steps[i] = steps[i-1] + steps[i-2]
        return steps[n]
        
