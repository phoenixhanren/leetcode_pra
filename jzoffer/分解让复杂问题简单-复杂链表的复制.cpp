#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

struct HashNode {
    int operator()(RandomListNode *const node) const {
        hash<int> ih;
        return ih(node->label);
    }
};

struct CMPNode {
    bool operator()(RandomListNode *const left, RandomListNode *const right) const {
        return left->label == right->label && left->next == right->next;
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        RandomListNode * p = pHead;
        RandomListNode * clone_head = new RandomListNode(p->label);
        clone_head->next = p->next;
        p->next = clone_head;
        p = clone_head->next;
        while (p != nullptr)
        {
            RandomListNode * clone_temp = new RandomListNode(p->label);
            clone_temp->next = p->next;
            p->next = clone_temp;
            p = clone_temp->next;
        }
        p = pHead;
        RandomListNode * p_clone;
        while (p != nullptr)
        {
            p_clone = p->next;
            if (p->random == nullptr)
                p_clone->random = nullptr;
            else
                p_clone->random = p->random->next;
            p = p_clone->next;           
        }
        p = pHead;
        p_clone = clone_head;
        while (p != nullptr)
        {
            p->next = p_clone->next;
            p = p->next;
            if (p == nullptr)
                p_clone->next = nullptr;
            else
                p_clone->next = p->next;
            p_clone = p_clone->next;
        }
        return clone_head;
    }

    RandomListNode * CloneHash(RandomListNode * pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        unordered_map<RandomListNode *, RandomListNode *, HashNode, CMPNode> n_map;
        RandomListNode * p = pHead;
        RandomListNode * clone_head = new RandomListNode(p->label);
        n_map.insert(p, clone_head);
        p = p->next;
        RandomListNode * clone_p = clone_head;
        while (p != nullptr)
        {
            RandomListNode * temp = new RandomListNode(p->label);
            clone_p->next = temp;
            clone_p = temp;
            n_map.insert(p, clone_p);
            p = p->next;
        }
        p = pHead;
        clone_p = clone_head;
        while (p != nullptr && clone_p != nullptr)
        {
            if (p->random == nullptr)
                clone_p->random = nullptr;
            else
            {
                clone_p->random = n_map[p->random];
            }
        }
        return clone_head;
    }
};