class Solution:
    def __init__(self):
        self.MAXL = 1005
        self.dp = [[-1] * self.MAXL for _ in range(self.MAXL)]
        self.s1 = ""
        self.s2 = ""

    def f(self, i, j):
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if self.s1[i - 1] == self.s2[j - 1]:
            self.dp[i][j] = self.f(i - 1, j - 1)
        else:
            self.dp[i][j] = min(
                self.f(i - 1, j) + ord(self.s1[i-1]),
                self.f(i, j - 1) + ord(self.s2[j-1]),
            )
        return self.dp[i][j]
        

    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        self.s1 = s1
        self.s2 = s2
        L1 = len(s1)
        L2 = len(s2)

        # 初始化 base case
        self.dp[0][0] = 0
        for i in range(1,L1 + 1):
            self.dp[i][0] = self.dp[i-1][0] + ord(s1[i-1])
        for j in range(1,L2 + 1):
            self.dp[0][j] = self.dp[0][j-1] + ord(s2[j-1])

        return self.f(L1, L2)
        
