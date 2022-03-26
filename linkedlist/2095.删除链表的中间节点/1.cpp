#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        if (!head || !head->next) 
        return NULL;
        ListNode* empty = new ListNode(0, head);
        ListNode* fast = empty, * slow = empty, * prev = NULL;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (!fast)
            prev->next = prev->next->next;
        else
            slow->next = slow->next->next;
        return empty->next;
    }
};