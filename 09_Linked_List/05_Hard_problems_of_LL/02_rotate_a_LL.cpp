//! Brute Force 

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        k %= n;

        for (int i = 0; i < k; i++) {
            ListNode* prev = nullptr;
            ListNode* temp = head;

            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = nullptr;
            temp->next = head;
            head = temp;
        }

        return head;
    }
};



//! Optimal Solution

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* temp = head;
        int n = 1;

        while(temp->next != nullptr){
            temp = temp->next;
            n++;
        }

        temp->next = head;

        k %= n;
        if(k == 0){
            temp->next = nullptr;
            return head;
        }

        temp = head;

        for(int i=0; i<n-k-1; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead; 
    }
};