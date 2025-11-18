class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        zero = False
        i = 0
        while i < len(bits):
            if bits[i] == 1:
                i += 2
                zero = False
            else:
                i += 1
                zero = True
        return zero

        
