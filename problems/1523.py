class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if (high - low) % 2 == 1:
            return (high-low+1) // 2
        return ((high-low) // 2 + (1 if high % 2 == 1 else 0))
        
