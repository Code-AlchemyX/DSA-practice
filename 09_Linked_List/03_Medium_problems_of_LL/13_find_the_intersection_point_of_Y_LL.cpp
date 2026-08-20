//! Brute Force --> TC = O(m*n)  and  SC = O(1)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        
        while (tempA != nullptr) {
            ListNode *tempB = headB;
            
            while (tempB != nullptr) {
                if (tempA == tempB) {
                    return tempA;
                }
                tempB = tempB->next;
            }
            
            tempA = tempA->next;
        }
        
        return nullptr;
    }
};

//! Better approach --> TC = O(m+n)   SC = O(m)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        
        ListNode *tempA = headA;
        while (tempA != nullptr) {
            visited.insert(tempA);
            tempA = tempA->next;
        }
        
        ListNode *tempB = headB;
        while (tempB != nullptr) {
            if (visited.count(tempB)) {
                return tempB;
            }
            tempB = tempB->next;
        }
        
        return nullptr;
    }
};

//! Optimal Approach 1  --> TC = O(m+n)  SC = O(1)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int sizeA = 0, sizeB = 0;

        while (tempA != nullptr) {
            sizeA++;
            tempA = tempA->next;
        }
        while (tempB != nullptr) {
            sizeB++; 
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        int size_diff = abs(sizeA - sizeB);
        if (sizeA > sizeB) {
            for (int i = 0; i < size_diff; i++) {
                tempA = tempA->next;
            }
        } else {
            for (int i = 0; i < size_diff; i++) {
                tempB = tempB->next;
            }
        }

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return tempA;
    }
};


//! Optimal Approach 2 -- BEST AMONGST ALL

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        return pA;
    }
};