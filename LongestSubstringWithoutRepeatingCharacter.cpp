class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            // Set to store the characters in the current substring
            std::unordered_set<char> set;

            // Start and end indices of the current substring
            int start = 0, end = 0;

            // Length of the longest substring found so far
            int longest = 0;

            while (end < s.length()) {
                // If the current character is not in the set, add it and move the end index forward
                if (set.find(s[end]) == set.end()) {
                    set.insert(s[end]);
                    end++;
                }
                // If the current character is already in the set, remove the characters from the start of the substring until the duplicate character is removed, and move the start index forward
                else {
                    set.erase(s[start]);
                    start++;
                }

                // Update the longest length if necessary
                longest = std::max(longest, end - start);
            }

        return longest;
        }

};
