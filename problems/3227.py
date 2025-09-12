class Solution:
    def doesAliceWin(self, s: str) -> bool:
        for ch in s:
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u':
                return True
        return False
