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