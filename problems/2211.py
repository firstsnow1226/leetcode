class Solution:
    def countCollisions(self, directions: str) -> int:
        pre = 'L'
        ans = 0
        rnum = 0
        for d in directions:
            if pre == 'L':
                pre = d
                continue
            elif pre == 'S':
                if d == 'L':
                    ans += 1
                    pre = 'S'
                else:
                    pre = d
            else:
                if d == 'L':
                    ans += 2 + rnum
                    rnum = 0
                    pre = 'S'
                elif d == 'S':
                    ans += 1 + rnum
                    rnum = 0
                    pre = 'S'
                else:
                    pre = 'R'
                    rnum += 1
        return ans
                
