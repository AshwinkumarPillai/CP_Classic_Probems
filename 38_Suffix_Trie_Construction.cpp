// Construct a suffix tree.

class Trie
{
private:
    class Node
    {
        unordered_map<char, Node *> children;
    };

public:
    Node root;
    char end_symbol = '*';
    void createSuffixTree(string &s)
    {

        for (int i = 0; i < (int)s.length(); i++)
        {
            insertSubstring(i, s);
        }
    }

    void insertSubstring(int i, string &s)
    {
        Node *node = root;
        if (!node)
        {
            node = new Node();
            for (int j = i; j < (int)s.length(); j++)
            {
                Node *child = new Node();
                node->children[s[j]] = child;
                node = child;
            }
        }
        else
        {
            for (int j = i; j < (int)s.length(); j++)
            {
                if (node->children.find(s[j]) == node->children.end())
                {

                    Node *child = new Node();
                    node->children[s[j]] = child;
                    node = child;
                }
                else
                {
                    Node *child = node->children[s[j]];
                    node = child;
                }
            }
        }
        node->children[end_symbol] = {};
    }

    bool endsWith(string s)
    {
        Node *node = root;
        for (char x : s)
        {
            if (node->children.find(x) == node->children.end())
            {
                return false;
            }
            node = node->children[x];
        }
        return (node->children.find(end_symbol) != node->children.end());
    }
};