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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        while(ptr1 && ptr2 && (ptr1 != ptr2))
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            /*
             * Any time they collide or reach end together without colliding 
             * then return any one of the pointers.
             **/

            if(ptr1 == ptr2) return ptr1;
            
            /*
             * If one of them reaches the end earlier then reuse it 
             * by moving it to the beginning of other list.
             * Once both of them go through reassigning, 
             * they will be equidistant from the collision point.
             **/
            if(ptr1 == nullptr) ptr1 = headB;
            
            if(ptr2 == nullptr) ptr2 = headA;
        }
        
        return ptr1 ? ptr1 : ptr2;
    }
};