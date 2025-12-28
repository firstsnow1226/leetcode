class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        for x in grid:
            for y in x:
                if y < 0:
                    ans += 1
        return ans
