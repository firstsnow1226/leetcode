class Solution:

    def check(self, num) -> bool:
        while num > 0:
            if num % 10 == 0:
                return False
            num //= 10
        return True

    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n):
            if self.check(i) and self.check(n-i):
                return [i,n-i]
        
