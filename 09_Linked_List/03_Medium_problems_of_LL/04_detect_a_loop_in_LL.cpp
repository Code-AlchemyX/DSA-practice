//! Brute Force method --> using unordered set

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_set<ListNode*> visited; 

        while(temp != nullptr){
            if(visited.count(temp)){
                return true;
            }
            
            visited.insert(temp);
            temp = temp->next;
        }

        return false;   
    }
};

//====================================================================================

//! Optimal approach --> using Slow-Fast pointers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }        

        return false;
    }
};