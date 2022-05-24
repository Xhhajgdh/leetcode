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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1 != NULL) carry += l1->val;
            if (l2 != NULL) carry += l2->val;
            ListNode* tmp = new ListNode(carry % 10);
            cur->next = tmp;
            cur = cur->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            carry /= 10;
        }
        return dummyHead->next;
    }
};