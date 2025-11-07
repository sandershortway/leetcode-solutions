
#include <iostream>

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
		ListNode dummy;
		ListNode* ptr = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				ptr->next = l1;
				l1 = l1->next;
			}
			else {
				ptr->next = l2;
				l2 = l2->next;
			}
			ptr = ptr->next;
		}

		// Attach last nodes
		ptr->next = l1 ? l1 : l2;

		return dummy.next;
	}
};

void traverse(ListNode* first) {
	ListNode* ptr = first;

	while (ptr) {
		std::cout << ptr->val << "->";
		ptr = ptr->next;
	}
	std::cout << "NULL" << std::endl;
}

int main()
{
	Solution sol;

	ListNode c{ 4 };
	ListNode b{ 2, &c };
	ListNode a{ 1, &b };

	traverse(&a);

	ListNode z{ 4 };
	ListNode y{ 3, &z };
	ListNode x{ 1, &y };

	traverse(&x);

	ListNode* res = sol.mergeTwoLists(&a, &x);

	traverse(res);

	res = sol.mergeTwoLists(nullptr, nullptr);

	traverse(res);

	res = sol.mergeTwoLists(nullptr, &z);

	traverse(res);

	res = sol.mergeTwoLists(&z, nullptr);

	traverse(res);

	res = sol.mergeTwoLists(&b, &x);

	traverse(res);

}