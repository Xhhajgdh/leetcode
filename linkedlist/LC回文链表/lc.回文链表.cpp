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
    ListNode* t;
    bool res = true;
public:
    bool recursivelyCheck(ListNode* head)
    {
        if (head == NULL) return true;
        res = recursivelyCheck(head->next) && (t->val == head->val);
        t = t->next;
        return res;
    }
    bool isPalindrome(ListNode* head) {
        t = head;
        return recursivelyCheck(head);

    }
};
