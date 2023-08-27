#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)
class NaiveSolution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      vector<int> result = {};
      nums = result;
      return 0;
    }

    auto result = new vector<int>();
    result->push_back(nums.front());
    for (int i : nums) {
      if (i != result->back()) {
        result->push_back(i);
      }
    }
    nums = *result;
    return nums.size();
  }
};

// time: O(n)
// space: O(1)
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.size();

    int position = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[position - 1]) {
        nums[position++] = nums[i];
      }
    }
    return nums.size();
  }
};

void print_vector(vector<int> &nums) {
  for (int i : nums) {
    cout << i << ",";
  }
}

int main() {
  Solution solution;

  vector<int> example1 = {1, 1, 2};
  vector<int> example2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  cout << "Input 1: ";
  print_vector(example1);
  cout << "\n"
       << "Answer: " << solution.removeDuplicates(example1) << endl;
  cout << "nums: ";
  print_vector(example1);
  cout << "\n\n";

  cout << "Input 2: ";
  print_vector(example2);
  cout << "\n"
       << "Answer: " << solution.removeDuplicates(example2) << endl;
  cout << "nums: ";
  print_vector(example2);
  cout << "\n\n";
}
