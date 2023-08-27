#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';

    stack<char> stack;

    for (char x : s) {
      if (x == '(' || x == '[' || x == '{') {
        stack.push(x);
      } else {
        if (stack.empty() || stack.top() != m[x])
          return false;
        stack.pop();
      }
    }
    if (stack.empty())
      return true;
    return false;
  }
};

int main() {
  ifstream inputfile("./input.txt");
  Solution solution;

  if (inputfile.is_open()) {
    string line;
    while (getline(inputfile, line)) {
      cout << "Input: " << line << endl;
      cout << "Output: " << (solution.isValid(line) ? "true" : "false")
           << "\n\n";
    }
  }
}
