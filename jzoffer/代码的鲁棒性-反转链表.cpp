struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        ListNode * left = pHead;
        ListNode * mid = left->next;
        if (mid == nullptr)
            return left;
        ListNode * right = mid->next;
        left->next = nullptr;
        while (right != nullptr)
        {
            mid->next = left;
            left = mid;
            mid = right;
            right = right->next;
        }
        mid->next = left;
        return mid;
    }
};