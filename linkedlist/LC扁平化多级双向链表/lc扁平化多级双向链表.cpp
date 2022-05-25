#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* newnode;
    Node* f(Node* p)
    {
        while (p->next)
        {
            if (p->child)
            {
                newnode = f(p->child);

                newnode->next = p->next;
                p->next->prev = newnode;
                p->child->prev = p;
                p->next = p->child;
                p->child = NULL;

                p = p->next;
            }
            else
                p = p->next;
        }
        if (p->child)
        {
            newnode = f(p->child);
            p->next = p->child;
            p->next->prev = p;
            p->child = NULL;
            while (p->next)
                p = p->next;
        }
        return p;
    }
    Node* flatten(Node* head) {
        Node* p = head;
        if (!head)
            return NULL;
        f(p);
        return head;
    }
};