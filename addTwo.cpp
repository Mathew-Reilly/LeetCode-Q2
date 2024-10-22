// Mathew Reilly
// Recusion Q2:
// Given 2 non-empty linked lists, representing two non-negative integers and stored in reverse order,
// each node containing a single digit, add the two numbers and return the sum as a linked list.
// You may assume neither number has a leading 0, except the number 0 itself.
#include <string>
#include <iostream>
using namespace std;

// Steps to Solve: (had to look at solutions for reference)
//  - Recognize this problem should not be solved recursively (even though it is marked as a recursive topic)
//    - Recursion complicates what is, in this case, a simple problem.
//  - Set up return value and support.
//  - Set iteration method: (Should check for break conditions. etc).

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
    // head node should be empty and just serve as a pointer to following nodes.
    // this allows the end of the list to avoid holding an empty listnode
    ListNode *sum = new ListNode(0);
    ListNode *tail = sum;
    bool finishedIteration = false;
    int carry = 0;

    int curVal;
    int val1 = 0;
    int val2 = 0;

    while (!finishedIteration)
    {

      (l1 != nullptr) ? val1 = l1->val : val1 = 0;
      (l2 != nullptr) ? val2 = l2->val : val2 = 0;

      // get the current sum and carry
      curVal = (val1 + val2 + carry) % 10;
      tail->next = new ListNode(curVal);
      // cout << "point 1\n";

      // hadles carries here
      if ((val1 + val2 + carry) >= 10)
      {
        // int remainder = 1;
        carry = (val1 + val2 + carry) / 10;
      }
      else
      {
        carry = 0;
      }

      if (l1->next != nullptr)
      {
        l1 = l1->next;
      }
      if (l2->next != nullptr)
      {
        l2 = l2->next;
      }
      tail = tail->next;

      // If boths next value is null and we have no carry, we have finished iterating.
      if (l1->next == nullptr && l2->next == nullptr)
      {
        if (carry != 0)
        {
          tail->next = new ListNode(carry);
          carry = 0;
        }
        finishedIteration = true;
        // continue;
      }
    }

    return sum->next;
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
  // string l1String = "[0]";
  // string l2String = "[0]";
  // string l1String = "[9,9,9,9,9,9,9]";
  // string l2String = "[9,9,9,9]";
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
