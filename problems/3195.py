class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        min_n = min_m = 1005
        max_n = max_m = -1

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    min_n = min(min_n,i)
                    max_n = max(max_n,i)
                    min_m = min(min_m,j)
                    max_m = max(max_m,j)
        if max_n == -1:
            return 0
        return (1+max_n-min_n)*(1+max_m-min_m)
