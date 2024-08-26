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
    void reverse(ListNode* prev, ListNode* curr, ListNode** newHead)
    {
        if(curr == NULL)
        {
            *newHead = prev;
            return;
        }
        
        reverse(curr, curr->next, newHead);
        
        curr->next = prev;
            
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        reverse(NULL, head, &newHead);
        //cout<<newHead<<endl;
        return newHead;
    }
};