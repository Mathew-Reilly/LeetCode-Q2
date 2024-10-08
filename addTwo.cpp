// Mathew Reilly
// Recusion Q2:
// Given 2 non-empty linked lists, representing two non-negative integers and stored in reverse order,
// each node containing a single digit, add the two numbers and return the sum as a linked list.
// You may assume neither number has a leading 0, except the number 0 itself.
#include <string>
#include <iostream>
using namespace std;

// FROM LEETCODE, a definition linked list nodes
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    // Check inner most conditions, if we are at the end of the list, return null.
    if (l1->next == nullptr || l2->next == nullptr)
    {
      return nullptr;
    }

    ListNode sum;
    sum.val = (sum.val + l1->val + l2->val) % 10;
    cout << "point 1\n";

    if ((l1->val + l2->val) > 10)
    {
      // int remainder = 1;
      sum.next = addTwoNumbers(l1->next, l2->next);
    }
    else
    {
      sum.next = addTwoNumbers(l1->next, l2->next);
    }

    cout << "point 2\n";

    return &sum;
  }
};

class Support
{
public:
  ListNode *parseListString(ListNode *head, string list)
  {
    ListNode *curNode;
    curNode = head;
    for (int i = 0; i < list.length(); i++)
    {
      if (list[i] >= '0' && list[i] <= '9')
      {
        cout << list[i] << "\n";
        if (curNode->next == nullptr)
        {
          curNode->next = new ListNode;
        }
        curNode->val = list[i] - '0';
        curNode = curNode->next;
      }
    }
    return head;
  }
  void printList(ListNode *listToPrint)
  {
    if (listToPrint == nullptr)
    {
      return;
    }
    while (listToPrint != nullptr)
    {
      cout << listToPrint->val << ", ";
      listToPrint = listToPrint->next;
    }
    cout << "\n";
    return;
  }
};

int main()
{
  cout << "program began\n";
  string l1String = "[2,4,3]";
  string l2String = "[5,6,4]";
  Support s;

  ListNode h1;
  ListNode h2;

  ListNode *list1 = s.parseListString(&h1, l1String);
  ListNode *list2 = s.parseListString(&h2, l2String);

  s.printList(list1);
  s.printList(list2);

  Solution sol;
  ListNode *res;

  res = sol.addTwoNumbers(list1, list2);

  s.printList(res);
  // while(res->next != nullptr)
  //{
  //   cout << res->val << ", ";
  // }
  return 0;
}
