#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *nex;
    Node(int val, Node *nex) : val(val), nex(nex) {}
};

Node *reverse(Node *head, Node *tail)
{
    if (head == nullptr || head->nex == nullptr)
    {

        tail = head;
        cout << tail->val << " " << head->val << endl;
        return head;
    }
    cout << head->val << " ";
    Node *ret = reverse(head->nex, tail);
    ret->nex = head;
    return head;
}

int main()
{
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
    Node *t = nullptr;
    reverse(head, t);
    cout << t << endl;
    while (t != nullptr)
    {
        cout << t->val << " ";
        t = t->nex;
    }
    return 0;
}
