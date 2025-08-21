class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        n = len(mat)
        m = len(mat[0])
        prs_c = [[ 0 for _ in range(m+1)] for _ in range(n+1)]

        ans = 0
        for i in range(1,n+1):
            for j in range(1,m+1):
                if mat[i-1][j-1] == 0:
                    prs_c[i][j] = 0
                    continue      
                prs_c[i][j] = 1 + prs_c[i-1][j]
        
        for i in range(1,n+1):
            for j in range(1,m+1):
                min_n = 1000
                for k in range(j,m+1):
                    min_n = min(min_n,prs_c[i][k])
                    ans += min_n

        return ans

