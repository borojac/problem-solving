#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node(int val)
    {
        this->val = val;
    }
    Node *next;
    Node *prev;
    int val;
};

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    Node *root = new Node(1);
    Node *rootTmp = root;
    for (int i = 2; i <= n; i++)
    {
        Node *tmp = new Node(i);
        rootTmp->next = tmp;
        tmp->prev = rootTmp;
        rootTmp = tmp;
    }
    root->prev = rootTmp;
    rootTmp->next = root;
    root = root->next;
    while (true)
    {
        cout << root->val << " ";
        if (root->next == root)
        {
            break;
        }
        root->prev->next = root->next;
        root->next->prev = root->prev;
        root = root->next->next;
    }

    return 0;
}