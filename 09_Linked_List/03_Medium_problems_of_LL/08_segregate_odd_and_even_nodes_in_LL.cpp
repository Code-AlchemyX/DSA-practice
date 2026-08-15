//! Brute Force 1 --> not preffered but self derived.

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> newLL;

        ListNode* curr = head;
        while (curr != nullptr) {
            newLL.push_back(curr->val);
            if (curr->next == nullptr) break; 
            curr = curr->next->next;
        }

        curr = head->next;
        while (curr != nullptr) {
            newLL.push_back(curr->val);
            if (curr->next == nullptr) break; 
            curr = curr->next->next;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;

        for (int v : newLL) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }

        return dummyHead->next;
    }
};



//! Brute Force 2


//! Optimal approach

