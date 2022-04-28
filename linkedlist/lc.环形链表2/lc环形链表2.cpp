#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        do {
            if (p2->next == nullptr || p2->next->next == nullptr) {
                return nullptr;
            }
            p1 = p1->next;
            p2 = p2->next->next;

        } while (p1 != p2);
        ListNode* p3 = head;
        while (p1 != p3) {
            p3 = p3->next;
            p1 = p1->next;
        }
        return p3;
    }
};
