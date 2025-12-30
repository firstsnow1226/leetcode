class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        ans = 0
        N = len(grid)
        M = len(grid[0])
        for i in range(N-2):
            for j in range(M-2):
                find = True
                appr = [0]*20
                for n in range(i,i+3):
                    for m in range(j,j+3):
                        if grid[n][m] == 0 or grid[n][m] > 9:
                            find = False
                        if appr[ grid[n][m] ] == 1:
                            find = False
                        appr[ grid[n][m] ] = 1
                tot = grid[i][j] + grid[i+1][j] + grid[i+2][j]

                for k in range(2):
                    if grid[i][j+k+1] + grid[i+1][j+k+1] + grid[i+2][j+k+1] != tot:
                        find = False
                for k in range(3):
                    if grid[i+k][j] + grid[i+k][j+1] + grid[i+k][j+2] != tot:
                        find = False
                if grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != tot:
                    find = False
                if grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != tot:
                    find = False
                if find:
                    ans += 1
        return ans
