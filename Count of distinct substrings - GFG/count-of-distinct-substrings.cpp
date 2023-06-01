//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct Node
{
    Node* links[26];
    bool flag;
    
    bool containsKey(char c)
    {
        return (links[c-'a'] != NULL);
    }
    
    void put(char c, Node* node)
    {
        links[c-'a'] = node;
    }
    
    Node* getNode(char c)
    {
        return links[c-'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
  
    bool isEnd()
    {
        return flag;
    }        
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Node* root = new Node();
    
    int cnt = 0;
    for(int i = 0 ; i < s.length(); i++)
    {
        Node* node = root;
        for(int j = i; j < s.length(); j++)
        {
            if(!node->containsKey(s[j]))
            {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->getNode(s[j]);
        }
    }
    
    return cnt+1;
    
}