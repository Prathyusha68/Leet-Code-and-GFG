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
    ListNode* reverse(ListNode* secHead)
    {
        ListNode* prev = NULL;
        ListNode* curr = secHead;
        
        while(curr != NULL)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while((fast->next != NULL) && (fast->next->next != NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        slow = slow->next;
        
        ListNode* temp = head;
        
        while((temp != NULL) && (slow != NULL))
        {
            if(temp->val != slow->val)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        
        return true;
    }
};