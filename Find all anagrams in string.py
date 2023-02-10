class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        map = {}
        for i in range(len(p)):
            map[p[i]] = 1 if p[i] not in map else map[p[i]] + 1

        windowSize = len(p)
        i ,j = 0, 0

        temp = {}
        ret = []
        while j < len(s):
            temp[s[j]] = 1 if s[j] not in temp else temp[s[j]] + 1
            # if the windowSize is equal to the size of string P
            if j - i + 1 == windowSize:
                # compare the two maps
                if temp == map:
                    ret.append(i)# append the beginning index
                # before advancing decrement ith element from the map
                temp[s[i]] -= 1
                if temp[s[i]] == 0:
                    del temp[s[i]]
                # advance the window size
                i += 1
            j += 1

        return ret
