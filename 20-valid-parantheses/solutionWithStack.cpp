#include <string>
#include <vector>
#include <iostream>
#include <stack>

class Solution
{
private:
    bool openCloseMatch(char open, char close) const
    {
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
    }

    bool isOpen(char c) const
    {
        return c == '(' || c == '[' || c == '{';
    }

public:
    bool isValid(const std::string& s)
    {
        std::stack<char> window;
        for (char c : s)
        {
            if (isOpen(c))
                window.push(c);
            else
            {
                if (window.empty())
                    return false;
                char last = window.top();
                if (!openCloseMatch(last, c))
                    return false;
                window.pop();
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