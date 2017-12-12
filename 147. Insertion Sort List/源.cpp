/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode * sorted = head;
		ListNode * unsorted = head->next;

		while (unsorted != nullptr)
		{
			ListNode * iter = head;
			if (head->val > unsorted->val)
			{
				ListNode * temp = unsorted->next;
				unsorted->next = head;
				head = unsorted;
				unsorted = temp;
			}
			else
			{
				while (iter != sorted)
				{
					if (iter->next->val > unsorted->val)
					{
						break;
					}
					iter = iter->next;
				}
				if (iter == sorted)
				{
					iter->next = unsorted;
					sorted = unsorted;
					unsorted = unsorted->next;
				}
				else
				{
					ListNode * iterNextTemp = iter->next;
					ListNode * unsortedNextTemp = unsorted->next;
					iter->next = unsorted;
					unsorted->next = iterNextTemp;
					unsorted = unsortedNextTemp;
				}
			}
		}

		sorted->next = nullptr;
		return head;
	}
};


int main()
{
	Solution s;
	
	ListNode a(1);
	ListNode b(1);
	//ListNode c(3);
	//ListNode d(2);
	//ListNode e(1);

	a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;

	

	ListNode * t = s.insertionSortList(&a);
	while (t != nullptr)
	{
		cout << t->val << " ";
		t = t->next;
	}
	return 0;
}