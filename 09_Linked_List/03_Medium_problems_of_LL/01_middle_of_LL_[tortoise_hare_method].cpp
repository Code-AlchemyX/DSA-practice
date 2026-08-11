//! Brute Force --> SC = O(1)

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
    ListNode* middleNode(ListNode* head) {
        int size_of_LL = 0;
        ListNode* temp1 = head;
        
        while(temp1 != nullptr){
            size_of_LL++;
            temp1 = temp1->next;
        }

        int middle = size_of_LL/2;
        ListNode* temp2 = head;

        for(int i=0; i<middle; i++){
            temp2 = temp2->next;
        }

        return temp2;
    }
};


//! ========================== Optimal method ==========================

