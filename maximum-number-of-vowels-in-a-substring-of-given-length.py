class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}

        i, j, mx, tmx = 0, 0, 0, 0
        # mx - max, tmx - temporary max

        while j < len(s):
            if s[j] in vowels:
                tmx += 1
            
            if j - i + 1 == k:
                mx = max(tmx, mx)

                if s[i] in vowels:
                    tmx -= 1
                i += 1
            
            j += 1

        return mx
