MAXN = 5005
class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        T = [0] * (len(skill)+1)

        for potion in mana:
            for i in range(len(skill)):
                T[i+1] = max(T[i], T[i+1]) + skill[i] * potion
            for i in range(len(skill)-1, -1, -1):
                T[i] = T[i+1] - skill[i] * potion
        return T[len(skill)]
