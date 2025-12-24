class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        s = sum(apple)
        capacity.sort(reverse = True)
        tot = 0
        for i in range(len(capacity)):
            tot += capacity[i]
            if tot >= s:
                return i+1
