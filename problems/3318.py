class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        f = [0]*55
        ans = []
        for i in range(k):
            f[ nums[i] ] += 1
        for i in range(len(nums)-k+1):
            tmp = f.copy()
            tot = 0
            for j in range(x):
                max_n = -1
                cnt = 0
                for m in range(len(tmp)):
                    if tmp[m] > cnt:
                        cnt = tmp[m]
                        max_n = m
                        continue
                    elif tmp[m] == cnt:
                        max_n = m
                        continue
                tot += max_n * cnt
                tmp[max_n] = 0
            ans.append(tot)
            if i == len(nums)-k:
                break

            f[nums[i]] -= 1
            f[nums[i+k]] += 1
        return ans
                     
                
