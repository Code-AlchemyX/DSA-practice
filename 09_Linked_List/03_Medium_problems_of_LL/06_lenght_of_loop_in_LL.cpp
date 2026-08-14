//! Brute force --> using hashmaps and it's function.


//! Optimal approach 

/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                fast = fast->next;
                int length  = 1;
                
                while(fast != slow){
                    length++;
                    fast = fast->next;
                }
                
                return length;
            }
        }
        return 0;
    }
};
