//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        
        if((head == NULL) || (head->next == NULL))
            return head;
        
        while(curr != NULL)
        {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        head = reverse(head);
        Node* curr = head;
        int carry = 1;
        
        while(carry)
        {
            curr->data += carry;
            
            if(curr->data < 10)
                return reverse(head);
            else
                curr->data = 0;
                
            if(curr->next == NULL)
                break;
            else
                curr = curr->next;
        }
        
        curr->next = new Node(1);
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends