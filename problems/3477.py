class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:

        cnt = 0
        for fruit in fruits:
            now = 0
            while now < len(baskets):
                if fruit > baskets[now]:
                    now += 1
                    continue
                baskets[now] = 0
                cnt += 1
                break
        return len(baskets) - cnt
                
