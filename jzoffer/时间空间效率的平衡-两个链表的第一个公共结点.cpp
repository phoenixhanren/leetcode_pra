#include <stack>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode *> p1;
        stack<ListNode *> p2;
        ListNode * p1_p = pHead1;
        ListNode * p2_p = pHead2;
        ListNode * ret = nullptr;
        while (p1_p != nullptr)
        {
            p1.push(p1_p);
            p1_p = p1_p->next;
        }
        while (p2_p != nullptr)
        {
            p2.push(p2_p);
            p2_p = p2_p->next;
        }
        while (p1.empty() == false && p2.empty() == false && p1.top() == p2.top())
        {
            ret = p1.top();
            p1.pop();
            p2.pop();
        }
        return ret;
    }
};