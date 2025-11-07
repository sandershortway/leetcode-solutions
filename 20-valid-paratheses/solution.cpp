#include <string>
#include <vector>
#include <iostream>

class Solution
{
private:
    bool openCloseMatch(char open, char close)
    {
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
    }

    bool isOpen(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }

public:
    bool isValid(std::string s)
    {
        std::vector<char> window;
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s.at(i);
            if (isOpen(c))
                window.push_back(c);
            else
            {
                if (window.size() == 0)
                    return false;
                char last = window.at(window.size() - 1);
                if (!openCloseMatch(last, c))
                    return false;
                else
                    window.pop_back();
            }
        }

        return window.empty();
    }
};

int main()
{
    Solution sol;

    std::string input = "()";
    std::cout << input << " true -- " << sol.isValid(input) << std::endl;

    input = "()[]{}";
    std::cout << input << " true -- " << sol.isValid(input) << std::endl;

    input = "(]";
    std::cout << input << " false -- " << sol.isValid(input) << std::endl;

    input = "([])";
    std::cout << input << " true -- " << sol.isValid(input) << std::endl;

    input = "([)]";
    std::cout << input << " false -- " << sol.isValid(input) << std::endl;

    input = "[[]]";
    std::cout << input << " true -- " << sol.isValid(input) << std::endl;

    input = "(";
    std::cout << input << " false -- " << sol.isValid(input) << std::endl;

    input = "(()";
    std::cout << input << " false -- " << sol.isValid(input) << std::endl;

    input = "";
    std::cout << input << " true -- " << sol.isValid(input) << std::endl;

    input = "]";
    std::cout << input << " false -- " << sol.isValid(input) << std::endl;
}