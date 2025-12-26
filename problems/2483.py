class Solution:
    def bestClosingTime(self, customers: str) -> int:
        ans = 0
        t = 0
        for ch in customers:
            if ch == 'Y':
                ans += 1
        R = ans
        L = 0
        for i in range(len(customers)):
            if customers[i] == 'Y':
                R -= 1
            else:
                L += 1
            if L + R < ans:
                ans = L + R
                t = i+1
        return t

        
