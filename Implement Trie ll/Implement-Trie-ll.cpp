// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

#include <bits/stdc++.h>
struct Node
{
    Node *links[26];
    int prefixCnt = 0; // prefix count
    int endCnt = 0;    // end count

    bool containsKey(char c)
    {
        return (links[c - 'a'] != NULL);
    }

    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }

    Node *getNode(char c)
    {
        return links[c - 'a'];
    }

    void incrementEndCount()
    {
        endCnt++;
    }

    void incrementPrefixCount()
    {
        prefixCnt++;
    }

    void decrementEndCount()
    {
        endCnt--;
    }

    void decrementPrefixCount()
    {
        prefixCnt--;
    }

    int getEndCnt()
    {
        return endCnt;
    }

    int getPrefixCnt()
    {
        return prefixCnt;
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->getNode(word[i]);
            node->incrementPrefixCount();
        }

        node->incrementEndCount();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->getNode(word[i]);
        }

        return node->getEndCnt();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->getNode(word[i]);
        }

        return node->getPrefixCnt();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return;
            }
            node = node->getNode(word[i]);
            node->decrementPrefixCount();
        }

        node->decrementEndCount();
    }
};
