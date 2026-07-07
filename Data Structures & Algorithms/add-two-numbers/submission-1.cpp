/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num_one = 0, num_two = 0, c1 = 0, c2 = 0;
        while (l1 || l2) {
            if (l1) {
                num_one += l1->val * (int)pow(10, c1);
                l1 = l1->next;
                c1++;
            }
            if (l2) {
                num_two += l2->val * (int)pow(10, c2);
                l2 = l2->next;
                c2++;
            }
        }
        int sum = num_one+num_two;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        if (sum == 0) {
            return dummy;
        }
        while (sum){
            cur->next = new ListNode(sum % 10);
            sum /= 10;
            cur = cur->next;
        }
        return dummy->next;
    }
};
