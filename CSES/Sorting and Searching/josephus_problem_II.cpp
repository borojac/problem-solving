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

Node *moveK(Node *root, int k)
{
    for (int i = 0; i < k; i++)
    {
        root = root->next;
    }
    return root;
}

Node *moveKB(Node *root, int k)
{
    for (int i = 0; i < k; i++)
    {
        root = root->prev;
    }
    return root;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
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
    // root = root->next;
    root = moveK(root, k % n);
    // int l = k % n;
    while (true)
    {
        cout << root->val << " ";
        if (root->next == root)
        {
            break;
        }
        root->prev->next = root->next;
        root->next->prev = root->prev;
        n--;
        int mv = ((k) % n) + 1;
        int lv = n - mv + 1;
        if (mv <= lv)
        {
            root = moveK(root, mv);
        }
        else
        {
            root = moveKB(root, lv);
        }
    }

    return 0;
}