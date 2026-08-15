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
        // Base case: empty list or single element
        if (head == NULL || head->next == NULL) {
            return head;
        }

        vector<int> arr;
        ListNode* temp = head;

        // 1. Collect all odd-indexed nodes (1st, 3rd, 5th, ...) 
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // 2. Collect all even-indexed nodes (2nd, 4th, 6th, ...) 
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            arr.push_back(temp->val);
        }

        // 3. Re-assign values back into the linked list 
        temp = head;
        int i = 0;
        while (temp != NULL) {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};



//! Optimal approach


