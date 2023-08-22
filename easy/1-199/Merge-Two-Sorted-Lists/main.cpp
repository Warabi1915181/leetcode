#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time complexity: O(n+m)
// memory complexity: O(1)
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head, *curr;
    if (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        head = list1;
        while (list1 != nullptr && list2 != nullptr) {
          if (list1->next == nullptr) {
            list1->next = list2;
            break;
          }
          if (list1->next->val > list2->val) {
            ListNode *temp = list2;
            list2 = list1->next;
            list1->next = temp;
          } else {
            list1 = list1->next;
          }
        }
      } else {
        head = list2;
        while (list1 != nullptr && list2 != nullptr) {
          if (list2->next == nullptr) {
            list2->next = list1;
            break;
          }
          if (list2->next->val > list1->val) {
            ListNode *temp = list1;
            list1 = list2->next;
            list2->next = temp;
          } else {
            list2 = list2->next;
          }
        }
      }

    } else if (list1 == nullptr) {
      head = list2;
    } else {
      head = list1;
    }

    return head;
  }
};

ListNode *arrayToListNode(int numbers[], int length) {
  if (length == 0)
    return nullptr;
  ListNode *head = new ListNode(numbers[0]);
  ListNode *curr = head;
  for (int i = 1; i < length; ++i) {
    ListNode *next = new ListNode(numbers[i]);
    curr->next = next;
    curr = curr->next;
  }

  return head;
}

void printListNode(ListNode *p) {
  while (p != nullptr) {
    cout << p->val << " ";
    p = p->next;
  }
}

int main() {
  Solution solution;
  int list1_arr[3] = {1, 2, 3};
  int list2_arr[3] = {1, 3, 4};
  ListNode *list1 = arrayToListNode(list1_arr, 3),
           *list2 = arrayToListNode(list2_arr, 3);
  ListNode *result = solution.mergeTwoLists(list1, list2);
  printListNode(result);
}
