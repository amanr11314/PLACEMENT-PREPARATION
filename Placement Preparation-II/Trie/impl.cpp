#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int terminating;
    Node *nodes[26];
    Node *next(char c)
    {
        return nodes[c - 'a'];
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        this->root = new Node();
    }

    int query(string s)
    {
        Node *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr == nullptr)
            {
                return 0;
            }
            curr = curr->next(s[i]);
        }
        return curr->terminating;
    }

    void insert(string s)
    {
        Node *curr = root;

        for (int i = 0; i < s.length(); ++i)
        {
            if (curr->nodes[s[i] - 'a'] == nullptr)
            {
                curr->nodes[s[i] - 'a'] = new Node();
            }
            curr = curr->next(s[i]);
        }
        curr->terminating++;
    }
    void deleteString(string s)
    {
        Node *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr == nullptr)
            {
                // throw runtime_error(string("String doesn\'t exist"));
                throw -1;
            }
            curr = curr->next(s[i]);
        }
        if (curr->terminating > 0)
            curr->terminating--;
        else
        {
            // throw runtime_error(string("String doesn\'t exist"));
            throw -1;
        }
    }
    void update(string old, string newString)
    {
        deleteString(old);
        insert(newString);
    }
};

int main()
{

    vector<string> setOfStrings;
    setOfStrings.push_back("pqrs");
    setOfStrings.push_back("pqrs");
    setOfStrings.push_back("pprt");
    setOfStrings.push_back("psst");
    setOfStrings.push_back("qqrs");
    setOfStrings.push_back("psst");

    Trie trie = Trie();
    for (string s : setOfStrings)
    {
        trie.insert(s);
    }
    cout << trie.query("pqrs") << '\n';
    cout << trie.query("abc") << '\n';
    cout << trie.query("psst") << '\n';
    trie.deleteString("psst");
    cout << trie.query("psst") << '\n';
    puts("Before: ");
    cout << "pqrs = " << trie.query("pqrs") << endl;
    cout << "abcd = " << trie.query("abcd") << endl;

    trie.update("pqrs", "abcd");
    puts("After: ");
    cout << "pqrs = " << trie.query("pqrs") << endl;
    cout << "abcd = " << trie.query("abcd") << endl;

    return 0;
}