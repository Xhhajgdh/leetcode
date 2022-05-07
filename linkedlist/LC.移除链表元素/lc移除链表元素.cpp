
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
	ListNode* removeElements(ListNode* head, int val) {

		if (head == nullptr)
			return head;

		ListNode* h1 = head;

		ListNode* h2 = head;
		//    	int length = 0; 
		//    	while( h1 ){
		//    		h1 = h1->next;
		//    		length ++;
		//		}

		for (int i = 0; h1 != nullptr; i++) {

			
			if (h1->val == val) {

				if (h1 == head) {
					h2 = h1->next;
					head = h2;
					h1 = h1->next;
					continue;
				}
				h2->next = h1->next;
				h1 = h1->next;
				continue;
			}
			h2 = h1;
			h1 = h1->next;
		}
		return head;
	}
};
