#include <algorithm>
#include <climits>
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

/* Better Binary Search
 * time: O(log(min(m+n))) ; space: O(1)
 */
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Our algorithm assumes that the first array is shorter. So we swap when
    // it's not
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;

    while (left <= right) {
      int partitionA = (left + right) / 2;
      int partitionB = (m + n + 1) / 2 - partitionA;

      int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
      int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
      int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
      int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

      if (maxLeftA > minRightB) {
        right = partitionA - 1;
      } else if (maxLeftB > minRightA) {
        left = partitionA + 1;
      } else {
        if ((m + n) % 2 == 0) {
          return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
        } else {
          return max(maxLeftA, maxLeftB);
        }
      }
    }
    return 0.0;
  }
};

int main(void) {
  ifstream inputfile("./input.txt");
  LesserSolution lesserSolution;
  Solution solution;

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
      double fasterResult = solution.findMedianSortedArrays(A, B);

      // start solving
      cout << "first array: " << firArr << endl;
      cout << "second array: " << secArr << endl;
      cout << "result: " << result << endl;
      cout << "faster result: " << result << "\n\n";
    }
  }
}
