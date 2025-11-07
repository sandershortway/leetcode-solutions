#include <iostream>
#include <string>
#include <cassert>

int value(char c)
{
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:
            throw std::invalid_argument("Value for roman numeral only defined for 'I', 'V', 'X', 'L', 'C', 'D', 'M'.");
    }
}

class Solution {
public:
    int romanToInt(std::string s) {
        int total = 0;
        size_t index = 0;

        while (index < s.size())
        {
            char first = s[index];

            if (index == s.size() - 1)
                return total + value(s[index]);

            char second = s[index + 1];

            if (value(first) < value(second))
            {
                total += value(second) - value(first);
                index += 2;
            }
            else
            {
                total += value(first);
                index += 1;
            }
        }
        return total;
    }
};