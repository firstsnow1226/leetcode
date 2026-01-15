class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        hBars.sort()
        vBars.sort()

        n1 = n2 = cnt1 = cnt2 = 1
        for i in range(1,len(hBars)):
            if hBars[i] == hBars[i-1]+1:
                cnt1 += 1
            else:
                cnt1 = 1
            n1 = max(n1, cnt1)
        for i in range(1,len(vBars)):
            if vBars[i] == vBars[i-1]+1:
                cnt2 += 1
            else:
                cnt2 = 1
            n2 = max(n2, cnt2)
        width = min(n1, n2)
        return (width+1)*(width+1)

        
