#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

// Solve the problem by converting the number to a string
class Solution_String {
public:
  bool isPalindrome(int x) {
    std::string xs = std::to_string(x);
    char const *p1 = xs.c_str();         // track from the start of the number
    char const *p2 = p1 + xs.size() - 1; // track from the end of the number
    for (int i = 0; i < xs.size() / 2; ++i) {
      if (*p1 != *p2) {
        return false;
      }
      p1++;
      p2--;
    }
    return true;
  }
};

class Solution_Number {
public:
  bool isPalindrome(int x) {
    if (x == 0)
      return true;
    else if (x < 0 || x % 10 == 0)
      return false;

    int reversed_right = 0;
    int exponent = std::log10(x);
    while (x > reversed_right) {
      reversed_right = reversed_right * 10 + x % 10;
      x /= 10;
    }

    if (exponent % 2 == 0)
      return (x == reversed_right / 10);
    else
      return (x == reversed_right);
  }
};

int main() {
  std::ifstream inputfile("./input.txt");

  if (inputfile.is_open()) {
    std::string line;

    while (std::getline(inputfile, line)) {
      Solution_String solution_string;
      Solution_Number solution_number;
      int x = std::atoi(line.c_str());
      bool result_string = solution_string.isPalindrome(x);
      bool result_number = solution_number.isPalindrome(x);

      std::cout << "Number: " << x << std::endl;
      std::cout << "Result from solution 1: "
                << (result_string ? "true" : "false") << std::endl;
      std::cout << "Result from solution 2: "
                << (result_number ? "true" : "false") << std::endl;
      std::cout << "\n";
    }
  }
}
