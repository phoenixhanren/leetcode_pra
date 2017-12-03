#include <iostream>

using std::cin;
using std::cout;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tempVal = l1->val + l2->val;
		int addOn = 0;
		if (tempVal >= 10)
		{
			tempVal -= 10;
			addOn = 1;
		}
		ListNode * ret = new ListNode(tempVal);
		ListNode * retIter = ret;
		ListNode * l1Iter = l1->next;
		ListNode * l2Iter = l2->next;

		while (l1Iter != NULL && l2Iter != NULL)
		{
			tempVal = l1Iter->val + l2Iter->val + addOn;
			addOn = 0;
			if (tempVal >= 10)
			{
				tempVal -= 10;
				addOn = 1;
			}
			ListNode * tempNode = new ListNode(tempVal);
			retIter->next = tempNode;
			retIter = tempNode;
			l1Iter = l1Iter->next;
			l2Iter = l2Iter->next;
		}

		while (l1Iter != NULL)
		{
			tempVal = l1Iter->val + addOn;
			addOn = 0;
			if (tempVal >= 10)
			{
				tempVal -= 10;
				addOn = 1;
			}
			ListNode * tempNode = new ListNode(tempVal);
			retIter->next = tempNode;
			retIter = tempNode;
			l1Iter = l1Iter->next;
		}

		while (l2Iter != NULL)
		{
			tempVal = l2Iter->val + addOn;
			addOn = 0;
			if (tempVal >= 10)
			{
				tempVal -= 10;
				addOn = 1;
			}
			ListNode * tempNode = new ListNode(tempVal);
			retIter->next = tempNode;
			retIter = tempNode;
			l2Iter = l2Iter->next;
		}

		if (addOn != 0)
		{
			ListNode * tempNode = new ListNode(addOn);
			retIter->next = tempNode;
		}
		return ret;
	}

};

int main()
{
	ListNode two(2);
	ListNode four1(4);
	ListNode three(3);

	ListNode five(5);
	ListNode six(6);
	ListNode four2(4);

	two.next = &four1;
	four1.next = &three;

	five.next = &six;
	six.next = &four2;

	Solution s;

	ListNode * ret = s.addTwoNumbers(&two, &five);

	while (ret != NULL)
	{
		std::cout << ret->val << std::endl;
		ret = ret->next;
	}
	return 0;
}