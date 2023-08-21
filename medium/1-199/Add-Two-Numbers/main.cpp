#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = new ListNode(0);
    int carry = 0;
    ListNode *p = l1, *q = l2, *current = ans;
    while (p != nullptr || q != nullptr) {
      int x = (p != nullptr) ? p->val : 0;
      int y = (q != nullptr) ? q->val : 0;
      int sum = carry + x + y;
      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
      if (p != nullptr)
        p = p->next;
      if (q != nullptr)
        q = q->next;
    }
    if (carry > 0) {
      current->next = new ListNode(carry);
    }
    return ans->next;
  }
};

void printListNode(ListNode *p) {
  ListNode *current = p;
  if (p != nullptr) {
    std::cout << p->val;
  }
  while (current->next) {
    std::cout << " -> " << current->next->val;
    current = current->next;
  }
}

int main(void) {
  std::ifstream inputfile("./input.txt");
  Solution solution;
  if (inputfile.is_open()) {
    std::string line;

    while (std::getline(inputfile, line)) {
      ListNode *p = nullptr, *q = nullptr;
      std::stringstream ss(line);
      std::string firstStr, secondStr;
      std::vector<int> firstArr, secondArr;

      if (std::getline(ss, firstStr, ',')) {
        std::stringstream arraySS(firstStr);
        std::string elementStr;
        ListNode *current = p;

        while (std::getline(arraySS, elementStr, ' ')) {
          int element = stoi(elementStr);
          if (p == nullptr) {
            p = new ListNode(element);
            current = p;
          } else {
            current->next = new ListNode(element);
            current = current->next;
          }
        }
      }

      if (std::getline(ss, secondStr)) {
        std::stringstream arraySS(secondStr);
        std::string elementStr;
        ListNode *current = q;

        while (std::getline(arraySS, elementStr, ' ')) {
          int element = stoi(elementStr);
          if (q == nullptr) {
            q = new ListNode(element);
            current = q;
          } else {
            current->next = new ListNode(element);
            current = current->next;
          }
        }
      }

      ListNode *answer = solution.addTwoNumbers(p, q);

      std::cout << "First list: ";
      printListNode(p);
      std::cout << "\nSecond list: ";
      printListNode(q);
      std::cout << "\nAnswer: ";
      printListNode(answer);
      std::cout << "\n\n";
    }
  } else {
    std::cout << "Untable to read input file.\n";
    return 1;
  }

  return 0;
}
