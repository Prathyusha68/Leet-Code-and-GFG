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

struct query
{
    int x;
    int m;
    int ind;
    
    bool operator < (query const& q)
    {
        return (m < q.m);
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), -1);        
        vector<query> offlineQueries;
        Trie trie;
        
        for(int i = 0; i < queries.size(); i++)
        {
            query oq;
            oq.x = queries[i][0];
            oq.m = queries[i][1];
            oq.ind = i;
            offlineQueries.push_back(oq);
        }
        
        sort(offlineQueries.begin(), offlineQueries.end());
        
        sort(nums.begin(), nums.end());
        
        int ind = 0;
        
        for(int i = 0; i < offlineQueries.size(); i++)
        {
            int xi = offlineQueries[i].x;
            int mi = offlineQueries[i].m;
            int indQ = offlineQueries[i].ind;
            
            while((ind < nums.size()) && (nums[ind] <= mi))
            {
                trie.insert(nums[ind]);
                ind++;
            }
            
            if(ind != 0)
                ans[indQ] = trie.findMax(xi);
        }
                
        return ans;
        
    }
};