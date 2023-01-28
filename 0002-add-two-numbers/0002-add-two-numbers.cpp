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
        ListNode head(0);
        ListNode* ll = &head;
        int c = 0;// carry
        while(c || l1 || l2)
        {
            c += (l1? l1->val:0) + (l2? l2->val:0);
            
            ll->next = new ListNode(c%10);
            c /= 10;
            
            ll = ll->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;       
        }
        
        return head.next;        
    }
};