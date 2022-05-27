#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head, * p1 = head, * newhead = new Node(0);
        Node* t = newhead, * t1 = newhead; int a = 0; bool flag;
        if (!head)
            return NULL;
        while (p->next)
        {

            t->val = p->val;
            t->next = new Node(0);
            p = p->next; t = t->next;
        }
        t->val = p->val;
        t->next = NULL;
        t = newhead; p = head;
        while (t)
        {
            t1 = newhead;
            if (!p->random)
                flag = 0;
            else {
                a = 0;
                p1 = head;
                while (p1->next)
                {

                    if (p1 == p->random)
                        break;
                    p1 = p1->next;
                    a++;

                }
                flag = 1;
            }

            if (!flag)
                t->random = NULL;
            else {

                while (a--) {

                    t1 = t1->next;
                }
                t->random = t1;
            }
            t = t->next;
            p = p->next;
        }
        return newhead;
    }

};

