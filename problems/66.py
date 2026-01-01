class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        for x in digits:
            num *= 10
            num += x
        num += 1
        ans = []
        while num > 0:
            ans.append(num%10)
            num //= 10
        ans.reverse()
        return ans

