class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, size_t> lastPos;
        size_t max = 0, l = 0;

        for (size_t r = 0; r < s.size(); ++r) {
            char c = s[r];
            if (lastPos.count(c) && lastPos[c] >= l) {
                l = lastPos[c] + 1;
            }

            lastPos[c] = r;
            max = std::max(max, r - l + 1);
        }
        return static_cast<int>(max);
    }
};