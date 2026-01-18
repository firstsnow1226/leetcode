class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        N = len(grid)
        M = len(grid[0])
        max_size = min(N, M)
        for size in range(max_size, 0, -1):
            for i in range(0, N-size+1):
                for j in range(0, M-size+1):
                    find = True
                    tot = 0
                    for k in range(size):
                        tot += grid[i+k][j]
                    
                    for row in range(size):
                        now = 0
                        for k in range(size):
                            now += grid[i+k][j+row]
                        if now != tot:
                            find = False
                    for col in range(size):
                        now = 0
                        for k in range(size):
                            now += grid[i+col][j+k]
                        if now != tot:
                            find = False
                    now = 0
                    for k in range(size):
                        now += grid[i+k][j+k]
                    if now != tot:
                        find = False
                    now = 0
                    for k in range(size):
                        now += grid[i+k][j+size-k-1]
                    if now != tot:
                        find = False
                    
                    if find:
                        return size
                    
        
