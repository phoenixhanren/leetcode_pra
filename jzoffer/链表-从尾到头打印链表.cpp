#include <vector>
#include <stack>

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
    vector<int> printListFromTailToHeadVectorRI(ListNode* head) {
        vector<int> v;
        ListNode * p = head;
        while (p != nullptr)
        {
            v.push_back(p->val);
            p = p->next;
        }
        return vector<int>(v.rbegin(), v.rend());
    }

    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        ListNode * p = head;
        while (p != nullptr)
        {
            s.push(p->val);
            p = p->next;
        }
        vector<int> ret;
        while (s.empty() == false)
        {
            ret.push_back(s.top());
            s.pop();
        }
        return std::move(ret);
    }
};