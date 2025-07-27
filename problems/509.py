class Solution:
    def fib(self, n: int) -> int:
        f = [0]*35

        f[0] = 0
        f[1] = 1

        for i in range(2,35):
            f[i] = f[i-1] + f[i-2]
        return f[n]
