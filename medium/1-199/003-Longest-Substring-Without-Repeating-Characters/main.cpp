#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int len = s.length(), res = 0;
    std::unordered_map<char, int> charIndexMap;

    for (int i = 0, j = 0; i < len; ++i) {
      char currentChar = s[i];
      if (charIndexMap[currentChar] > 0) {
        j = std::fmax(charIndexMap[currentChar], j);
      }
      res = std::fmax(res, i - j + 1);
      charIndexMap[currentChar] = i + 1;
    }

    return res;
  }
};

int main(void) {
  std::ifstream inputfile("./input.txt");
  Solution solution;

  if (inputfile.is_open()) {
    std::string line;

    while (std::getline(inputfile, line)) {
      int len = solution.lengthOfLongestSubstring(line);
      std::cout << '"' << line << "\"\n" << len << std::endl;
    }

    return 0;
  } else {
    std::cout << "Failed to open file";
    return 1;
  }
}
