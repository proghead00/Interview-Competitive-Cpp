#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    char data;
    unordered_map<char, node *> m;
    bool isTerminal;

    node(int d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node('\0');
    }

    void insert(string word)
    {
        node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                node *n = new node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                return false;
            }
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }
};

int main()
{
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;

    for (auto w : words)
    {
        t.insert(w);
    }

    int q;
    cin >> q;

    string searchWord;
    while (q--)
    {
        cin >> searchWord;
        if (t.search(searchWord))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
