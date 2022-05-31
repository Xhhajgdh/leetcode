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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* start = head;
        ListNode* end = head;
        int cnt = 1;
        while (end->next) {
            end = end->next;
            ++cnt;
        }
        k = k % cnt;
        while (k--) {
            end->next = start;
            start = end;
            while (end->next != start) {
                end = end->next;
            }
        }
        end->next = nullptr;
        return start;
    }
};
