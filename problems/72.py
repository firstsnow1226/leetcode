class Solution:
    def __init__(self):
        self.MAXL = 505
        self.dp = [[-1] * self.MAXL for _ in range(self.MAXL)]
        self.s1 = ""
        self.s2 = ""

    def f(self, i, j):
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        if self.s1[i - 1] == self.s2[j - 1]:
            self.dp[i][j] = self.f(i - 1, j - 1)
        else:
            self.dp[i][j] = 1 + min(
                self.f(i - 1, j),     # 刪除
                self.f(i, j - 1),     # 插入
                self.f(i - 1, j - 1)  # 替換
            )
        return self.dp[i][j]

    def minDistance(self, word1: str, word2: str) -> int:
        self.s1 = word1
        self.s2 = word2
        L1 = len(word1)
        L2 = len(word2)

        # 初始化 base case
        for i in range(L1 + 1):
            self.dp[i][0] = i
        for j in range(L2 + 1):
            self.dp[0][j] = j

        return self.f(L1, L2)

