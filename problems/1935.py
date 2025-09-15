class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(' ')
        ans = 0
        
        for word in words:
            broken = False
            for i in range(len(brokenLetters)):
                if brokenLetters[i] in word:
                    broken = True
                    break
            if not broken:
                ans += 1

        return ans
