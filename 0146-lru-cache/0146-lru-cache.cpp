struct Node
{
    Node* prev;
    Node* next;
    int key;
    int val;
    
    Node(int key, int val):key{key}, val{val}, prev{nullptr}, next{nullptr}
    {
    }  
};

class LRUCache {
private:
    Node *head = nullptr, *tail = nullptr;
    int maxCap, currCap;
    unordered_map<int, Node*> hash;
    
public:
    LRUCache(int capacity) {
        maxCap = capacity;
        currCap = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    
    void addNode(Node* newNode)
    {
        Node* tmp = head->next;
        newNode->next = head->next;
        newNode->prev = head;
        head->next = newNode;
        tmp->prev = newNode;
    }
    
    void delNode(Node* node)
    {
        Node* tmp = node;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(hash.find(key) != hash.end())
        {
            Node* node = hash[key];
            int ans = node->val;
            hash.erase(key);
            delNode(node);
            addNode(node);
            hash[key] = head->next;
            return ans;
        }
        
        return -1;
    }
     
    void put(int key, int value) {
        Node* newNode = new Node(key, value);
        if(hash.find(key) != hash.end())
        {
            delNode(hash[key]);
            addNode(newNode);
            hash[key] = head->next;
        }
        else
        {
            if(currCap == maxCap)
            {
                hash.erase(tail->prev->key);
                delNode(tail->prev);                
            }
            else
            {
                currCap++;
            }
            addNode(newNode);
            hash[key] = head->next;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */