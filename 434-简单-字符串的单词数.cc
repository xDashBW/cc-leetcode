#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
      int i = num1.length() - 1;
      int j = num2.length() - 1;
      int add = 0;
      std::string ret = "";
      while (i >= 0 || j >= 0 || add > 0) {
        int x = (i >= 0) ? num1[i] - '0' : 0;
        int y = (j >= 0) ? num2[j] - '0' : 0;
        int result = x + y + add;
        ret.push_back('0' + result % 10);
        add = result / 10;
        --i;
        --j;
      }
      std::reverse(ret.begin(), ret.end());
      return ret;
    }
};
