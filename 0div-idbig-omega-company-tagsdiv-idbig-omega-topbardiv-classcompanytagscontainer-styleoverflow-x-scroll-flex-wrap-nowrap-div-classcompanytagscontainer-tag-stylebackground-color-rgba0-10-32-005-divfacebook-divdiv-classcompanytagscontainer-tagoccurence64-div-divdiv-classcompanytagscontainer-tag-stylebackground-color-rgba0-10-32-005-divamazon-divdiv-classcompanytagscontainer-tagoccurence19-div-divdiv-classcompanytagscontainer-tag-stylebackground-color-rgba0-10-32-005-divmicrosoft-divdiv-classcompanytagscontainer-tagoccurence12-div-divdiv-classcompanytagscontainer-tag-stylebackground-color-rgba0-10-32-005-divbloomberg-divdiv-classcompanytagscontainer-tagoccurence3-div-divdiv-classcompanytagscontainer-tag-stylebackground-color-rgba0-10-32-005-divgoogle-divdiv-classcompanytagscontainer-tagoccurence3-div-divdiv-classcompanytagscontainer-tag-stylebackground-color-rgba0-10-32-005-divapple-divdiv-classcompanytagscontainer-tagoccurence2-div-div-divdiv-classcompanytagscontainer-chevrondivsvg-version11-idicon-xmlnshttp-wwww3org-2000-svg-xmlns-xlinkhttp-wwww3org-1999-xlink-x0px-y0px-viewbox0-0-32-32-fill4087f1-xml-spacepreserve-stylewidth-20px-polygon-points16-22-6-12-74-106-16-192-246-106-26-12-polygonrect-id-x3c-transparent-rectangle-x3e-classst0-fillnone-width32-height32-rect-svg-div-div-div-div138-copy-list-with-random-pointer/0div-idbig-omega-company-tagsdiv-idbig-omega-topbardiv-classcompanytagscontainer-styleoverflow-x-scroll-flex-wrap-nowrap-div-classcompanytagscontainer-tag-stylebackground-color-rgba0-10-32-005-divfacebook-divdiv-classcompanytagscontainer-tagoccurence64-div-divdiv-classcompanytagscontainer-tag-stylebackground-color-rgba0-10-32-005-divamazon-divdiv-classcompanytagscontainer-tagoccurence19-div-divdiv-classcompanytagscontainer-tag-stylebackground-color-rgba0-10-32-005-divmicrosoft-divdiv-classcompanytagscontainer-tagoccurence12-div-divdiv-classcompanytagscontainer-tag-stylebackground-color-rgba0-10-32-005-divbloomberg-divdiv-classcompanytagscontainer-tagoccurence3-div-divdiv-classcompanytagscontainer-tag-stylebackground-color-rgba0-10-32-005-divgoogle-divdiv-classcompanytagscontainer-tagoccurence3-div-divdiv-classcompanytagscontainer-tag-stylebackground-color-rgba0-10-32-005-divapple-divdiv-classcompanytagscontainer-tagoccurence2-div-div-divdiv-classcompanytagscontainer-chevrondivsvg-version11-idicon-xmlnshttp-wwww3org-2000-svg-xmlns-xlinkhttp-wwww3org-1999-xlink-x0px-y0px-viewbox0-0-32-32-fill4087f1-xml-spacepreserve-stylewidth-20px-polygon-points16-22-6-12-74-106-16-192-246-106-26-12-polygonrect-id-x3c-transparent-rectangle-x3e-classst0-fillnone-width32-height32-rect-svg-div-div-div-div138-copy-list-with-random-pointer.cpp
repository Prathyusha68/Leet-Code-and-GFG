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
        //Step 1 : Add deep copied nodes
        Node* curr = head;
        while(curr != NULL)
        {
            Node* tmp = curr->next;
            Node* newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = tmp;
            curr = tmp;
        }

        // Step 2 : Connect random pointers of deep copied nodes
        curr = head;
        while(curr != NULL)
        {
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        // Step 3 : Seperate Deep copied nodes and given i/p nodes
        curr = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(curr != NULL)
        {
            Node* tmp = curr->next->next;
            res->next = curr->next;
            curr->next = tmp;
            curr = curr->next;
            res = res->next;
        }

        return dummy->next;
    }
};