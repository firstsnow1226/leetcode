class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ans = []
        ans.append(words[0])
        for i in range(1,len(words)):
            s1 = sorted(words[i-1])
            s2 = sorted(words[i])
            if s1 == s2:
                continue
            ans.append(words[i])
        return ans
