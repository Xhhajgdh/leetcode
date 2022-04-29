#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* copyA = headA;
        ListNode* copyB = headB;
        while (copyA != copyB)
        {
            copyB = copyB ? copyB->next : headA;
            copyA = copyA ? copyA->next : headB;
        }
        return copyB;
    }
};
