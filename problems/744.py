class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        for x in letters:
            if ord(x) > ord(target):
                return x
        return letters[0]
