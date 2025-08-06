class Solution:
    def __init__(self):
        self.MAXL = 1005
        self.dp = [[-1] * self.MAXL for _ in range(self.MAXL)]
        self.s1 = ""
        self.s2 = ""
    
    def f(self,i,j):
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if i < j:
            self.dp[i][j] = 0
        elif j == 0:
            self.dp[i][j] = 1
        elif self.s1[i-1] != self.s2[j-1]:
            self.dp[i][j] = self.f(i-1,j)
        else:
            self.dp[i][j] = self.f(i-1,j-1) + self.f(i-1,j)
        return self.dp[i][j]

    def numDistinct(self, s: str, t: str) -> int:
        self.s1 = s
        self.s2 = t

        return self.f(len(s),len(t))

        

