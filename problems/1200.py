class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        min_n = arr[1] - arr[0]
        ans = []
        for i in range(len(arr)-1):
            if arr[i+1]-arr[i] > min_n:
                continue
            elif arr[i+1]-arr[i] < min_n:
                ans.clear()
            ans.append([arr[i],arr[i+1]])
            min_n = min(min_n, arr[i+1]-arr[i])
        return ans
