class Solution:
    def sortVowels(self, s: str) -> str:
        consos = []
        vowels = []
        for ch in s:
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U':
                vowels.append(ch)
            else:
                consos.append(ch)
        vowels.sort()

        ans = ""
        p1 = p2 = 0
        for ch in s:
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U':
                ans += vowels[p1]
                p1 += 1
            else:
                ans += consos[p2]
                p2 += 1
        return ans
