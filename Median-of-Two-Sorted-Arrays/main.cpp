#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/* Somewhat Binary Search
 * time: O(log(m) + log(n)) ; space: O(log(m) + log(n))
 *
 * This algorithm is inspired by binary search. The idea is that if A_mid <=
 * B_mid, we have A_left <= B_mid <= B_right, i.e. A_left <= B_right. Obviously,
 * we know A_left <= A_right. Hence, we have A_left <= (A_right) union
 * (B_right). So if we are looking at the median of sorted(A+B), we know that it
 * must not be in A_left. Therefore, we can leave out A_left. The rest is
 * recursion.
 */
class LesserSolution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int na = int(nums1.size()), nb = int(nums2.size());
    int n = na + nb;
    if (n % 2) {
      return solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1);
    } else {
      return 1.0 *
             (solve(nums1, nums2, n / 2 - 1, 0, na - 1, 0, nb - 1) +
              solve(nums1, nums2, n / 2, 0, na - 1, 0, nb - 1)) /
             2;
    }
  }

  // this function returns the k-th smallest element in a sorted merged array
  // sorted(A+B), given A and B are already sorted.
  int solve(vector<int> &A, vector<int> &B, int k, int aStart, int aEnd,
            int bStart, int bEnd) {
    // If the segment of an array is empty, it means we have passed all its
    // elements. so we just return the corresponding elements
    if (aEnd < aStart) {
      return B[k - aStart];
    }
    if (bEnd < bStart) {
      return A[k - bStart];
    }

    int aMiddleIndex = (aStart + aEnd) / 2, bMiddleIndex = (bStart + bEnd) / 2;
    int aMiddleValue = A[aMiddleIndex], bMiddleValue = B[bMiddleIndex];

    // If k is on the right half of A+B, remove the left half (which is
    // smaller).
    if (aMiddleIndex + bMiddleIndex < k) {
      if (aMiddleValue < bMiddleValue) {
        return solve(A, B, k, aMiddleIndex + 1, aEnd, bStart, bEnd);
      } else {
        return solve(A, B, k, aStart, aEnd, bMiddleIndex + 1, bEnd);
      }
    }
    // Otherwise, remove the right half (which is larger).
    else {
      if (aMiddleValue < bMiddleValue) {
        return solve(A, B, k, aStart, aEnd, bStart, bMiddleIndex - 1);
      } else {
        return solve(A, B, k, aStart, aMiddleIndex - 1, bStart, bEnd);
      }
    }
    return -1;
  }
};

int main(void) {
  ifstream inputfile("./input.txt");
  LesserSolution lesserSolution;

  if (inputfile.is_open()) {
    string line;

    while (getline(inputfile, line)) {
      stringstream ss(line);
      string firArr, secArr;
      vector<int> A, B;

      if (getline(ss, firArr, ',')) {
        stringstream arraySS(firArr);
        string eleStr;
        while (getline(arraySS, eleStr, ' ')) {
          int ele = stoi(eleStr);
          A.push_back(ele);
        }
      }

      if (getline(ss, secArr)) {
        stringstream arraySS(secArr);
        string eleStr;
        while (getline(arraySS, eleStr, ' ')) {
          int ele = stoi(eleStr);
          B.push_back(ele);
        }
      }

      double result = lesserSolution.findMedianSortedArrays(A, B);

      // start solving
      cout << "first array: " << firArr << endl;
      cout << "second array: " << secArr << endl;
      cout << "result: " << result << "\n\n";
    }
  }
}
