class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        pre = 0
        ans = 0
        for s in bank:
            now = 0
            for ch in s:
                if ch == '1':
                    now += 1
            ans += now*pre
            if now != 0:
                pre = now
        return ans
