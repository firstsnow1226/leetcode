class Solution:

    def longestPalindrome(self, s: str) -> str:
        ans = 0
        ss = ""
        for i in range(len(s)):
            cnt = 1
            dis = 1
            while i-dis >= 0 and i+dis < len(s):
                if s[i-dis] != s[i+dis]:
                    break
                cnt += 2
                dis += 1
            if cnt > ans:
                ans = cnt
                ss = s[i - dis + 1 : i + dis]
        for i in range(len(s)-1):
            if s[i] != s[i+1]:
                continue
            cnt = 2
            dis = 1
            while i-dis >= 0 and i+1+dis < len(s):
                if s[i-dis] != s[i+1+dis]:
                    break
                cnt += 2
                dis += 1
            if cnt > ans:
                ans = cnt
                ss = s[i - dis + 1 : i+1+dis]

        return ss
