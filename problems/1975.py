class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        ans = 0
        num = 0
        min_n = 100005
        for row in matrix:
            for x in row:
                if x < 0:
                    num += 1
                    ans += -x
                else:
                    ans += x
                min_n = min(min_n, abs(x))
                
        if num % 2 == 0:
            return ans
        return ans - 2*min_n

