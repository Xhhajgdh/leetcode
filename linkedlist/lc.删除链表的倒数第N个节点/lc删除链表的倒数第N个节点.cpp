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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* p = head;
        int len = 1;
        while (p->next != nullptr) {
            p = p->next;
            len++;
        }
        p = head;
        if (len == n) {
            head = head->next;
            return head;
        }
        for (int i = 0; i < len - n - 1; i++) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }

};