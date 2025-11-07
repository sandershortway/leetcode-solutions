class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string target = strs.at(0);

        for (size_t char_idx = 0; char_idx < target.size(); char_idx++)
        {
            for (size_t str_idx = 1; str_idx < strs.size(); str_idx++)
            {
               if (char_idx >= strs.at(str_idx).size() || strs.at(str_idx).at(char_idx) != target.at(char_idx))
                    return target.substr(0, char_idx);
            }
        }

        return target;
    }
};