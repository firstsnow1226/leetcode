class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq = [0]*26

        for ch in s:
            freq[ ord(ch) - ord('a') ] += 1
        vowel_n = conso_n = 0

        for i in range(26):
            if i in [0, 4, 8, 14, 20]:
                vowel_n = max(vowel_n,freq[i])
            else:
                conso_n = max(conso_n,freq[i])            

        return vowel_n + conso_n
