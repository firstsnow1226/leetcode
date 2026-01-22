class Solution:
    def __init__(self):
        self.arr = []

    def check(self):
        for i in range(len(self.arr)-1):
            if self.arr[i] > self.arr[i+1]:
                return False
        return True


    def minimumPairRemoval(self, nums: List[int]) -> int:
        ans = 0
        self.arr = nums
        while not self.check():
            pos = 0
            mini = self.arr[0]+self.arr[1]
            for i in range(len(self.arr)-1):
                if self.arr[i]+self.arr[i+1] < mini:
                    mini = self.arr[i]+self.arr[i+1]
                    pos = i
            self.arr.pop(pos)
            self.arr.pop(pos)
            self.arr.insert(pos, mini)
            ans += 1
        return ans
        
