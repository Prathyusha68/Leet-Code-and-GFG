struct Node
{
    Node* links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    
    void addKey(int bit, Node* node)
    {
        links[bit] = node;
    }
    
    Node* getNode(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node* root;
    
public:
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit))
            {
                node->addKey(bit, new Node());
            }
            
            node = node->getNode(bit);
        }
    }
    
    int findMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit))
            {
                maxNum |= (1 << i);
                node = node->getNode(1-bit);
            }
            else
            {
                node = node->getNode(bit);
            }           
        }
        
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie; 
        for(auto it : nums)
        {
            trie.insert(it);
        }
        
        int maxi = 0;
        for(auto it : nums)
        {
            maxi = max(maxi, trie.findMax(it));
        }
        
        return maxi;
    }
};