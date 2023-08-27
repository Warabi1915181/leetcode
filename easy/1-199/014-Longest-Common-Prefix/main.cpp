#include <_types/_uint8_t.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";

    string prefix = "";
    uint8_t index = 0;
    bool stop = false;

    while (!stop) {
      char common = strs[0][index];
      for (string s : strs) {
        if (index >= s.length()) {
          stop = true;
          break;
        }
        if (s[index] != common) {
          stop = true;
          break;
        }
      }
      if (!stop) {
        prefix += common;
        index++;
      }
    }

    return prefix;
  }
};

int main() {
  Solution solution;
  vector<string> strs1, strs2;
  strs1.push_back("flower");
  strs1.push_back("flow");
  strs1.push_back("flight");
  strs2.push_back("dog");
  strs2.push_back("racecar");
  strs2.push_back("car");

  cout << "strs: ";
  for (string s : strs1) {
    cout << s << ", ";
  }
  cout << "\n";
  cout << "Common Prefix: " << '"' << solution.longestCommonPrefix(strs1) << '"'
       << "\n\n";
  cout << "strs: ";
  for (string s : strs2) {
    cout << s << ", ";
  }
  cout << "\n";
  cout << "Common Prefix: " << '"' << solution.longestCommonPrefix(strs2) << '"'
       << endl;
}
