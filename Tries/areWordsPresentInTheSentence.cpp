#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class node
{
public:
    char data;
    unordered_map<char, node *> children;
    bool isTerminal;

    node(int d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
public:
    node *root;

    Trie()
    {
        root = new node('\0');
    }

    void insert(string word)
    {
        node *temp = root;

        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                node *n = new node(ch);
                temp->children[ch] = n;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m)
{
    node *temp = t.root;
    for (int j = i; j < document.length(); j++)
    {
        char ch = document[j];
        if (temp->children.count(ch) == 0)
            return;

        temp = temp->children[ch];

        if (temp->isTerminal)
        {
            string out = document.substr(i, j - i + 1);
            m[out] = true;
        }
    }
    return;
}

void documentSearch(string document, vector<string> words)
{
    Trie t;
    for (auto w : words)
    {
        t.insert(w);
    }

    unordered_map<string, bool> m;
    for (int i = 0; i < document.length(); i++)
    {
        searchHelper(t, document, i, m);
    }
    for (auto w : words)
    {
        if (m[w])
            cout << w << ":True " << endl;
        else
            cout << w << ":False "  << endl;
    }
    return;
}

int main()
{
    string document = " little cute cat loves to code in c++, java and python";
    vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};

    documentSearch(document, words);
}
