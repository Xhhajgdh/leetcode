#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* f = head;
        ListNode* s = head;
        do {
            if (f->next == nullptr || f->next->next == nullptr) return false;
            f = f->next->next;
            s = s->next;
        } while (f != s);
        return true;
    }
};
