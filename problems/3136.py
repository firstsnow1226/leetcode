class Solution:
    def isValid(self, word: str) -> bool:
        vowel_cnt = 0
        conso_cnt = 0
        for ch in word:
            if ch == '@' or ch == '#' or ch == '$':
                return False
            if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U' :
                vowel_cnt += 1
            elif 'a' <= ch and ch <= 'z' or 'A' <= ch and ch <= 'Z':
                conso_cnt += 1

        if vowel_cnt !=0 and conso_cnt != 0 and len(word)>=3:
            return True
        return False
