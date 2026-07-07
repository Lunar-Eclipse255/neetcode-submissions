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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode sol(0);
        ListNode* deep = &sol;
        ListNode* one = list1;
        ListNode* two = list2;
        while (one && two) {
            if (one->val < two->val){
                deep->next = one;
                one = one->next;
            }
            else {
                deep->next = two;
                two = two->next;
            }
            deep = deep->next;
        }
        if (one) {
            deep->next = one;
            one = one->next;
        }
        if (two) {
            deep->next = two;
            two = two->next;
        }
        return sol.next;
    }
};
