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

class SuffixTrie
{
    node *root;

public:
    SuffixTrie()
    {
        root = new node('\0');
    }

    void insert_helper(string word)
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

    void insert(string word) {
        // pick all substrings from idx i till end of string and call insert_helper
        for (int i = 0; word[i] != NULL; i++) {
            insert_helper(word.substr(i));
        }
    }
};

int main()
{
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};

    SuffixTrie t;
    t.insert(input);

    for (auto sf : suffixes)
    {
        if (t.search(sf))
            cout << "Yes" << " ";
        else
            cout << "No" << " ";

    }

}
