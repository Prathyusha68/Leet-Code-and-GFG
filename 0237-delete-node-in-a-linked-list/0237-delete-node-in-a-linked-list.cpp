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
    void deleteNode(ListNode* node) {
        // Instead of deleting the "node" 
        // Copy values of next node to curr node to be deleted
        // and delete the next node
        auto nextNode = node->next;
        *node = *node->next;
        // above line is similar to 
        // node->val = node->next->val;
        // node->next = node->next->next;
        delete nextNode;
    }
};