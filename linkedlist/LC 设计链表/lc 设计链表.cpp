#include<iostream>
using namespace std;
class MyLinkedList {
    struct L
    {
        int val;
        L* next;
        L(int x) :val(x), next(nullptr) {}
    };
    L* head;
    int l;
public:
    
    MyLinkedList()
    {
        head = new L(0);
        l = 0;
    }

    int get(int index)
    {
        if (index >= l || index < 0)
            return -1;
        L* ptr = head;
        for (int i = 0; i <= index; i++)
        {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val)
    {
        L* ptr = new L(val);
        ptr->next = head->next;
        head->next = ptr;
        l++;
    }

    void addAtTail(int val)
    {
        L* ptr = new L(val);
        L* n = head;
        for (int i = 0; i < l; i++)
        {
            n = n->next;
        }
        n->next = ptr;
        l++;
    }

    
    void addAtIndex(int index, int val)
    {
        if (index<0 || index>l)
            return;
        L* ptr = head;
        L* ins = new L(val);
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ins->next = ptr->next;
        ptr->next = ins;
        l++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= l)
            return;
        L* ptr = head;
        L* del;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        del = ptr->next;
        ptr->next = del->next;
        delete del;
        l--;
    }
};
