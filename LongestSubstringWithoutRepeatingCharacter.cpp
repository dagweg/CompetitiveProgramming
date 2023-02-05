class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) return s.size();

        ios::sync_with_stdio(0);
        cin.tie(0);

        unordered_set<char> letters;

        int longest = 1;
        int left = 0, right = 1;
        letters.insert(s[left]);

        while(right < s.size())
        {
            if(letters.count(s[right])){
                letters.erase(s[left]);
                left++;
            }
            else
            {
                letters.insert(s[right]);
                longest = max(longest, right - left + 1);
                right++;
            }
        }
        return longest;

    }
};
