class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        ans.append([1])

        for i in range(1,numRows):
            tmp = [1]
            for j in range(i):
                tmp.append(ans[i-1][j] + (0 if j==i-1 else ans[i-1][j+1]))
            ans.append(tmp)
        return ans


        
