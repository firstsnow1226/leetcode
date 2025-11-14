class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        prs = [[0 for _ in range(n)] for _ in range(n)]
        for query in queries:
            x1 = query[0]
            y1 = query[1]
            x2 = query[2]
            y2 = query[3]
            prs[x1][y1] += 1
            if x2+1 < n:
                prs[x2+1][y1] -= 1
            if y2+1 < n:
                prs[x1][y2+1] -= 1
            if x2+1 < n and y2+1 < n:
                prs[x2+1][y2+1] += 1
        for i in range(n):
            for j in range(n):
                if i > 0:
                    prs[i][j] += prs[i-1][j]
                if j > 0:
                    prs[i][j] += prs[i][j-1]
                if i > 0 and j > 0:
                    prs[i][j] -= prs[i-1][j-1]

        return prs
