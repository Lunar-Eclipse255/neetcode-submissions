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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> node_set;
        ListNode* node = head;
        while (node) {
            if (node_set.find(node) != node_set.end()) {
                return true;
            }
            node_set.insert(node);
            node = node->next;
        }
        return false;
    }
};
