class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        MOD = 10**9 + 7
        hFences.insert(0, 1)
        hFences.append(m)
        vFences.insert(0, 1)
        vFences.append(n)
        hlen = []
        vlen = []

        for i in range(len(hFences)):
            for j in range(i+1, len(hFences)):
                hlen.append(abs(hFences[j]-hFences[i]))
        hlen.sort(reverse=True)
        for i in range(len(vFences)):
            for j in range(i+1, len(vFences)):
                vlen.append(abs(vFences[j]-vFences[i]))
        vlen.sort(reverse=True)
        hptr = 0
        vptr = 0
        while hptr < len(hlen) and vptr < len(vlen):
            if hlen[hptr] == vlen[vptr]:
                ans = hlen[hptr]*hlen[hptr]
                ans %= MOD
                return ans
            elif hlen[hptr] > vlen[vptr]:
                hptr += 1
            else:
                vptr += 1
        return -1
        
