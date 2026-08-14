//! Brute force 

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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0;
        int right = arr.size()-1;

        while(left < right){
            if(arr[left] != arr[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr != nullptr){
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }

        ListNode* lefthalf = head;
        ListNode* righthalf = prev;

        while(righthalf != nullptr){
            if(lefthalf->val != righthalf->val){
                return false;
            }

            lefthalf = lefthalf->next;
            righthalf = righthalf->next;
        }

        return true;
    }
};