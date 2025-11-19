class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        find = True
        while find:
            find = False
            for num in nums:
                if num == original:
                    original *= 2
                    find = True
        return original
        
