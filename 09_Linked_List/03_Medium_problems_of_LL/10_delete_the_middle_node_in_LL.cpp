//! Optimal code 1 --> Two passes.

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int res = n / 2;
        temp = head;
        while (temp != nullptr) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        ListNode* middle = temp->next;
        temp->next = temp->next->next;
        delete middle;

        return head;
    }
};


//! Optimal approach --> Single pass and expected

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow; 

        return head;
    }
};