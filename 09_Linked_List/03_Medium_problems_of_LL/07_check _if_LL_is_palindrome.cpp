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





//! The code above and this code both are OPTIMAL .... but in an interview changing the given input is considered as bad practice and hence we return our original array after palindrome check.
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* newHead = reverseList(slow->next);

        // 3. Compare halves
        ListNode* left = head;
        ListNode* right = newHead;
        bool result = true;

        while (right != nullptr) {
            if (left->val != right->val) {
                result = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        // 4. Restore original list
        slow->next = reverseList(newHead);

        return result;
    }
};