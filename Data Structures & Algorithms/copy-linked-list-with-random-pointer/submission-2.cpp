/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_copy_map;
        old_copy_map[NULL] = NULL;
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            old_copy_map[cur]=copy;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            Node* copy = old_copy_map[cur];
            copy->next = old_copy_map[cur->next];
            copy->random = old_copy_map[cur->random];
            cur=cur->next;
        }
        return old_copy_map[head];
    }
};
