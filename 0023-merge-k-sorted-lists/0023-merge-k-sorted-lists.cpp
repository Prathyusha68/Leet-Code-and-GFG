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
private:
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r)
        {
            return l->val > r->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        if(lists.size() == 0)
            return NULL;
        
        // add 1st elements of all lists into priority queue
        for(auto ls : lists)
        {
            if(ls)
                pq.push(ls);
        }
        
        if(pq.empty())
            return NULL;
        
        ListNode* res = pq.top();
        pq.pop();
        
        ListNode* tmp = res;
        if(res->next)
            pq.push(res->next);
        
        while(!pq.empty())
        {
            tmp->next = pq.top();
            pq.pop();
            tmp = tmp->next;
            if(tmp->next)
                pq.push(tmp->next);
        }
        
        return res;
    }
};