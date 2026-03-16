
#include <cassert>
#include <optional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Rounding
// If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1],
// then round the integer to remain in the range. Specifically, integers less
// than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1
// should be rounded to 2^31 - 1.

int toInt(char c) {
  // Convert digit char to int
  return c - '0';
}

class Solution1 {
public:
  int myAtoi(string s) {
    int result = 0;
    optional<bool> isNeg = nullopt;
    bool readNum = false;

    for (char c : s) {
      if (readNum) {
        if (!isdigit(c))
          break;
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && toInt(c) > 7)) {
          return isNeg ? INT_MIN : INT_MAX;
        }
        result = 10 * result + toInt(c);
      } else if (c == ' ')
        continue;
      else if (c == '-' || c == '+') {
        if (!isNeg.has_value()) {
          if (c == '-')
            isNeg = true;
          if (c == '+')
            isNeg = false;
        } else {
          return 0;
        }
      } else if (isdigit(c)) {
        readNum = true;
        result = toInt(c);
      } else
        break;
    }
    return isNeg ? -result : result;
  }
};

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        bool isNeg = false;
        bool readNum = false;

        for (char c : s) {
            if (readNum) {
                if (!isdigit(c))
                    break;
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && toInt(c) > 7)) {
                    return isNeg ? INT_MIN : INT_MAX;
                }
                result = 10 * result + toInt(c);
            }
            else if (c == ' ')
                continue;
            else if (c == '-' || c == '+') {
                readNum = true;
                if (c == '-') isNeg = true;
            }
            else if (isdigit(c)) {
                readNum = true;
                result = toInt(c);
            }
            else
                break;
        }
        return isNeg ? -result : result;
    }
};

int main() {
  Solution sol;

  vector<pair<string, int>> tests = {
      {"4", 4},
      {"04", 4},
      {" 4", 4},
      {"42", 42},
      {"-42", -42},
      {"-042", -42},
      {"  -042", -42},
      {"-00042", -42},
      {"42c", 42},
      {"4c2", 4},
      {"1337c0d3", 1337},
      {"0-1", 0},
      {"words and 987", 0},
      {"-1123u3761867", -1123},
      {"00000-42a1234", 0},
      {"+-2", atoi("+-2")},
      {"2147483647", 2147483647},    // INT_MAX
      {"2147483648", 2147483647},    // INT_MAX + 1
      {"9999999999", 2147483647},    // way overflow positive
      {"-2147483648", -2147483648},  // INT_MIN
      {"-2147483649", -2147483648},  // INT_MIN - 1
      {"-9999999999", -2147483648},  // way overflow negative
      {"  21474836470", 2147483647}, // large with whitespace
      {"+1", 1},
      {"--1", atoi("--1")},
      {"+-12", atoi("+-12")}};

  int passed = 0;
  for (const auto &[input, expected] : tests) {
    int result = sol.myAtoi(input);
    if (result == expected) {
      passed++;
      cout << "\"" << input << "\" -> " << expected << endl;
    } else {
      cout << "\"" << input << "\" -> expected " << expected << ", got "
           << result << endl;
    }
  }

  cout << "\n" << passed << "/" << tests.size() << " tests passed" << endl;

  return 0;
}