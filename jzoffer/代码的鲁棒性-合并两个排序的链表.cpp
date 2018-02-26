struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;
        ListNode * left_pointer = pHead1;
        ListNode * right_pointer = pHead2;
        ListNode * new_list;
        if (left_pointer->val < right_pointer->val)
        {
            new_list = left_pointer;
            left_pointer = left_pointer->next;
        }
        else 
        {
            new_list = right_pointer;
            right_pointer = right_pointer->next;
        }
        ListNode * new_list_pointer = new_list;
        while (left_pointer != nullptr && right_pointer != nullptr)
        {
            if (left_pointer->val < right_pointer->val)
            {
                new_list_pointer->next = left_pointer;
                new_list_pointer = left_pointer;
                left_pointer = left_pointer->next;
            }
            else
            {
                new_list_pointer->next = right_pointer;
                new_list_pointer = right_pointer;
                right_pointer = right_pointer->next;                
            }
        }
        while (left_pointer != nullptr)
        {
            new_list_pointer->next = left_pointer;
            new_list_pointer = left_pointer;
            left_pointer = left_pointer->next;            
        }
        while (right_pointer != nullptr)
        {
            new_list_pointer->next = right_pointer;
            new_list_pointer = right_pointer;
            right_pointer = right_pointer->next;            
        }
        new_list_pointer->next = nullptr;
        return new_list;
    }
};