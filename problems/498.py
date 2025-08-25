class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans = []
        n = len(mat)
        m = len(mat[0])

        for i in range(0,n+m-1):
            if i % 2 == 0:
                for j in range((0 if i < n else i-n+1),min(m,i+1)):
                    ans.append(mat[i-j][j])
            else:
                for j in range((0 if i < m else i-m+1),min(n,i+1)):
                    ans.append(mat[j][i-j])
        return ans
        
