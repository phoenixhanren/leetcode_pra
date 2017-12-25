#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		quickSort(head, nullptr);
		return head;
	}

	/*
	[head, tail)
	*/

	void quickSort(ListNode * start, ListNode * end) {
		if (start != end)
		{
			ListNode * mid = partition(start, end);
			quickSort(start, mid);
			quickSort(mid->next, end);
		}
	}

	/*
	[head, tail)
	*/

	ListNode * partition(ListNode * start, ListNode * end) {
		//ListNode * pivot = start;
		//ListNode * i = start->next;
		int pivot = start->val;
		ListNode * loc = start;

		for (ListNode * i = start->next; i != end; i = i->next)
		{
			if (i->val < pivot)
			{
				loc = loc->next;
				swap(loc->val, i->val);
			}
		}
		swap(start->val, loc->val);
		return loc;
	}


};