class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        ans = 0
        N = len(bottomLeft)
        for i in range(N):
            x1 = bottomLeft[i][0]
            y1 = bottomLeft[i][1]
            x2 = topRight[i][0]
            y2 = topRight[i][1]
            for j in range(i+1,N):
                x3 = bottomLeft[j][0]
                y3 = bottomLeft[j][1]
                x4 = topRight[j][0]
                y4 = topRight[j][1]

                w = min(x2, x4) - max(x1, x3)
                h = min(y2, y4) - max(y1, y3)

                if w > 0 and h > 0:
                    side = min(w, h)
                    ans = max(ans, side*side)
        return ans
                

        
