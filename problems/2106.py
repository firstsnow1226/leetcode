MAXP = 200005
class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        prs = [0]*MAXP

        for fruit in fruits:
            prs[ fruit[0] + 1 ] += fruit[1]
        for i in range(1,MAXP):
            prs[i] += prs[i-1]
        startPos += 1


        ans = 0
        for i in range(k+1):
            L = max(1,(startPos - i))
            R = startPos
            if i <= k//3:
                R += k - 2*i
            else:
                R += (k - i)//2
            R = min(R,MAXP-1)
            ans = max(ans,prs[R]-prs[L-1])
            #print(i,L,R,ans)
        return ans
