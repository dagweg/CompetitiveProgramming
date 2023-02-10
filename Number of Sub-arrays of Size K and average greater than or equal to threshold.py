class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        i,j =0, 0
        temp = 0
        ret = 0
        while j < len(arr):
            temp += arr[j]
            if j - i + 1 == k:
                if temp//k >= threshold:
                    ret+=1
                temp -= arr[i]
                i+=1
            j+=1
        return ret
            
