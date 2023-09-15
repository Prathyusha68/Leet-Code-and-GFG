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
    void reverse(ListNode* start, ListNode* end)
    {
        ListNode* prev = NULL;
        ListNode* curr = start;
        while(prev != end)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* end = head;
        int len = 0;
        while(end != NULL)
        {
            len++;
            if(len%k == 0)
            {
                ListNode* start = prev->next;
                ListNode* nextStart = end->next;
                reverse(start, end);
                prev->next = end;
                start->next = nextStart;
                prev = start;
                end = nextStart;
            }
            else
            {
                end = end->next;
            }
        }
        return dummy->next;
    }
};