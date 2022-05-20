#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, * p2 = l2, * head = new ListNode(0), * p3;
        ListNode* p4 = head;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        while (1)
        {
            if (p2->val >= p1->val)
            {
                p4->next = p1;
                p4 = p1;
                p3 = p1->next;
                p1->next = NULL;
                p1 = p3;
            }
            else
            {
                p4->next = p2;
                p4 = p2;
                p3 = p2->next;
                p2->next = NULL;
                p2 = p3;
            }
            if (!p3)
            {
                if (!p1)
                    p4->next = p2;
                if (!p2)
                    p4->next = p1;
                return head->next;
            }

        }
    }
};
