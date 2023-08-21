#include <_types/_uint8_t.h>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class NaiveSolution {
public:
  int romanToInt(string s) {
    char prev = ' ';
    uint16_t sum = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
      switch (s[i]) {
      case 'I':
        if (prev == 'V' || prev == 'X') {
          sum -= 1;
        } else {
          sum += 1;
        }
        prev = 'I';
        break;

      case 'X':
        if (prev == 'L' || prev == 'C') {
          sum -= 10;
        } else {
          sum += 10;
        }
        prev = 'X';
        break;
      case 'C':
        if (prev == 'D' || prev == 'M') {
          sum -= 100;
        } else {
          sum += 100;
        }
        prev = 'C';
        break;

      case 'V':
        sum += 5;
        prev = 'V';
        break;

      case 'L':
        sum += 50;
        prev = 'L';
        break;

      case 'D':
        sum += 500;
        prev = 'D';
        break;

      case 'M':
        sum += 1000;
        prev = 'M';
        break;

      default:
        break;
      }
    }

    return sum;
  }
};

class Solution_With_Map {
public:
  int romanToInt(string s) {
    unordered_map<char, int> m;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    uint16_t result = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
      if (m[s[i]] < m[s[i + 1]]) {
        result -= m[s[i]];
      } else {
        result += m[s[i]];
      }
    }

    result += m[s[s.length() - 1]];
    return result;
  }
};

int main() {
  Solution_With_Map solution;
  ifstream inputfile("./input.txt");

  if (inputfile.is_open()) {
    string line;

    while (getline(inputfile, line)) {
      int result = solution.romanToInt(line);

      cout << "Roman: " << line << endl;
      cout << "Integer: " << result << endl;
      cout << "\n";
    }
  }
}
