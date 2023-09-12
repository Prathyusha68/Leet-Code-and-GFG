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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        // Maintain the distance btw slow and fast same as dist btw
        // last Nth node and last node
        for(int i = 0; i < n; i++)
            fast = fast->next;
        
        /*if((head == NULL) || ((head->next == NULL) && (n == 0)))
            return head;
        
        if((head->next == NULL) && (n == 1))
        {
            delete head;
            return NULL;
        }*/
            
        
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        
        //delete delNode;
        
        return start->next;
    }
};