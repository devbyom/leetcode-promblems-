class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        int lastIndex[256];
        for (int i = 0; i < 256; i++) {
            lastIndex[i] = -1;
        }

        for (int right = 0; right < n; right++) {
            char currentChar = s[right];
            if (lastIndex[(int)currentChar] >= left) {
                left = lastIndex[(int)currentChar] + 1;
            }
            lastIndex[(int)currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};