#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
      std::string newstr;
      for (auto i : s) {
        if (i == ' ') {
          newstr.append("%20");
        } else {
          newstr.push_back(i);
        }
      }
      return newstr;
    }
};

int main () {
  Solution s;
  std::string str = "We are happy.";
  auto newstr = s.replaceSpace(str);
  std::cout << newstr << std::endl;
}