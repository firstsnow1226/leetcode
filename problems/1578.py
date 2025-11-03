class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = 0
        pre = colors[0]
        tot = neededTime[0]
        max_n = neededTime[0]
        for i in range(1,len(colors)):
            if colors[i] == pre:
                tot += neededTime[i]
                max_n = max(max_n, neededTime[i])
            else:
                ans += (tot-max_n)
                tot = neededTime[i]
                max_n = neededTime[i]
            pre = colors[i]
        ans += (tot-max_n)
        return ans


