#include <cstddef>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr)
            return nullptr;
        int len = 0;
        ListNode * ptr = pListHead;
        while (ptr != nullptr)
        {
            ++len;
            ptr = ptr->next;
        }
        if (k > len)
            return nullptr;
        int count = len - k;
        ptr = pListHead;
        while (count > 0)
        {
            ptr = ptr->next;
            --count;
        }
        return ptr;
    }
    ListNode* FindKthToTailTwoPointer(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr)
        {
            return nullptr;
        }
        int count = 0;
        ListNode * p = pListHead;
        ListNode * q = pListHead;
        while (p != nullptr)
        {
            if (count++ >= k)
                q = q->next;
            p = p->next;
        }
        if (count < k)
            return nullptr;
        return q;
    }
};