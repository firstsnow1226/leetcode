class Solution:
    def hasSameDigits(self, s: str) -> bool:
        while len(s) > 2:
            s2 = ""
            for i in range(len(s)-1):
                s2 += (str)((int(s[i])+int(s[i+1]))%10)
            s = s2
        if s[0] == s[1]:
            return True
        return False
        
