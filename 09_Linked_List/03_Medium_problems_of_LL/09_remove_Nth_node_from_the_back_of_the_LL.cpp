//! Brute force --> Two pass method


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;

        while(temp != nullptr){
            size++;
            temp = temp->next;
        }

        if(size == n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int node_from_front = size - n;

        ListNode* prev = head;
        for(int i=1; i<node_from_front; i++){
            prev = prev->next;
        }

        ListNode* nodeToDelete = prev->next;
        prev->next = prev->next->next;
        delete nodeToDelete;

        return head;
    }
};


//! Optimal approach 

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }

        ListNode* slow = head;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
    }
};

