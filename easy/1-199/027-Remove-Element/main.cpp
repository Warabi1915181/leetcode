#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int position = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        nums[position++] = nums[i];
      }
    }

    return position;
  }
};

void printVector(vector<int> &v) {
  for (int i : v) {
    cout << i << ",";
  }
}

int main() {
  Solution solution;

  vector<int> example1 = {3, 2, 2, 3}, example2 = {0, 1, 2, 2, 3, 0, 4, 2};
  int val1 = 3, val2 = 2;

  cout << "Example 1: ";
  printVector(example1);
  cout << "\n"
       << "val1: " << val1 << endl;
  cout << "Solution:";
  int k = solution.removeElement(example1, val1);
  printVector(example1);
  cout << "\n"
       << "k: " << k << "\n\n";

  cout << "Example 2: ";
  printVector(example2);
  cout << "\n"
       << "val2: " << val2 << endl;
  cout << "Solution:";
  k = solution.removeElement(example2, val2);
  printVector(example2);
  cout << "\n"
       << "k: " << k << "\n\n";
}
