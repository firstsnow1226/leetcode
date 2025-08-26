class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = 0
        max_L = 0
        for x in dimensions:
            if x[0]*x[0]+x[1]*x[1] > max_L:
                max_L = x[0]*x[0]+x[1]*x[1]
                ans = x[0]*x[1]
            elif x[0]*x[0]+x[1]*x[1] == max_L:
                ans = max(ans,x[0]*x[1])
        return ans
