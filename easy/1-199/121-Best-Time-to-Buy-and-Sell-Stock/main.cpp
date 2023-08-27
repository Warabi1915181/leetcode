#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// helper function
int max(int a, int b) { return a > b ? a : b; }

// calculate the difference between the stock price in each timestamp and its
// future price (O(n^2))
class Naive_Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<int> diff;
    int maximum = 0;
    for (int i = 0; i < prices.size(); ++i) {
      for (int j = i + 1; j < prices.size(); ++j) {
        maximum = max(prices[j] - prices[i], maximum);
      }
    }
    return maximum;
  }
};

// O(n)
// Step backward in time
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int highest_sale_price = prices[prices.size() - 1];
    int maxProfit = 0;
    for (int i = prices.size() - 2; i >= 0; --i) {
      highest_sale_price = max(highest_sale_price, prices[i]);
      maxProfit = max(maxProfit, highest_sale_price - prices[i]);
    }

    return maxProfit;
  }
};

int main() {
  Solution solution;
  ifstream inputfile("./input.txt");

  if (inputfile.is_open()) {
    string line;
    while (getline(inputfile, line)) {
      stringstream ss(line);
      string num_str;
      vector<int> prices;

      cout << "Input: [";
      while (getline(ss, num_str, ',')) {
        int num = atoi(num_str.c_str());
        prices.push_back(num);
        cout << num << ',';
      }
      cout << "]" << endl;

      cout << "Output: " << solution.maxProfit(prices) << "\n\n";
    }
  }
}
