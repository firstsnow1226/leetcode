class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        ans = 0
        pre_h = 0
        cond = 0 # 0 up 1 down
        max_n = target[0]
        pre = target[0]

        for i in range(1,len(target)):
            if cond == 0 and target[i] >= pre:
                pre = target[i]
                max_n = pre
                continue
            if cond == 1 and target[i] > pre:
                ans += max_n - pre_h
                pre_h = pre
                pre = target[i]
                max_n = target[i]
                cond = 0
                continue
            cond = 1
            pre = target[i]
        ans += max_n - pre_h
        return ans


