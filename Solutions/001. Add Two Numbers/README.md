# Two Sum
## Description
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse** order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
### Example
>Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
>
>Output: 7 -> 0 -> 8
>
>Explanation: 342 + 465 = 807.
## Solutions
### solution
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = 0;
        ListNode dummy(0), *tail = &dummy;
        for (int i = 0; num || l1 || l2; tail = tail->next) {
            int sum = 0;
            if (l1) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + num;
            if (sum / 10 > 0) num = sum / 10;
            else num = 0;
            sum = sum % 10;
            tail->next = new ListNode(sum);
        }
        return dummy.next;
    }
};
```