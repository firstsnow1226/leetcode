class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans = 0
        L = 0
        num1 = -1
        num2 = -1
        cnt1 = 0
        cnt2 = 0
        for num in fruits:
            if num == num1:
                cnt1 += 1
                ans = max(ans,cnt1+cnt2)
                continue
            elif num == num2:
                cnt2 += 1
                ans = max(ans,cnt1+cnt2)
                continue
            elif cnt1 != 0 and cnt2 != 0:
                while cnt1 != 0 and cnt2 != 0:
                    if num1 == fruits[L]:
                        cnt1 -= 1
                    else:
                        cnt2 -= 1
                    L += 1
            if cnt1 == 0:
                num1 = num
                cnt1 = 1
            else:
                num2 = num
                cnt2 = 1
            ans = max(ans,cnt1+cnt2)
        return ans

        
