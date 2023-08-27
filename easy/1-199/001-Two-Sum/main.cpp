#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      int goal;
      goal = target - nums[i];
      if (numMap.count(goal)) {
        return {i, numMap[goal]};
      }

      numMap[nums[i]] = i;
    }
    return {};
  }
};

void printArray(std::vector<int> arr) {
  for (int ele : arr) {
    std::cout << ele << " ";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {

  Solution solution;

  std::ifstream inputfile("./input.txt");
  if (inputfile.is_open()) {

    std::string line;
    while (std::getline(inputfile, line)) {
      std::stringstream ss(line);
      std::string numberStr, arrayStr;
      int number;
      std::vector<int> arr;

      if (std::getline(ss, numberStr, ',')) {
        // Convert number string to integer
        number = stoi(numberStr);
        std::cout << "Number: " << number << std::endl;
      }

      if (std::getline(ss, arrayStr)) {
        // Parse the array string and store elements in a vector
        std::stringstream arraySS(arrayStr);
        std::string elementStr;
        while (std::getline(arraySS, elementStr, ' ')) {
          if (elementStr == " ")
            continue;
          // convert element string to integer
          int element = stoi(elementStr);
          arr.push_back(element);
        }

        std::cout << "Array: ";
        for (int element : arr) {
          std::cout << element << " ";
        }
        std::cout << std::endl;
      }

      // print answer
      std::vector<int> answerArr = solution.twoSum(arr, number);
      std::cout << "Answer: ";
      printArray(answerArr);
      std::cout << std::endl;
    }

  } else {
    printf("Unable to read input file.\n");
    return 1;
  }

  return 0;
}
