/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto comp = [](ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp); // min_heap
        for (auto *l : lists)
        {
            if (l) pq.push(l);
        }

        ListNode dummy;
        ListNode *cur = &dummy;

        while (!pq.empty())
        {
            auto *l = pq.top(); pq.pop();
            cur->next = l;
            cur = cur->next;
            l = l->next;
            if (l) pq.push(l);
        }
        return dummy.next;
    }
};
