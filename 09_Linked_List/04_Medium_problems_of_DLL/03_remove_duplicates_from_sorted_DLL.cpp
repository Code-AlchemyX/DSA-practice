//! Optimal approach

/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        if(!headRef) return nullptr;
        
        Node* dummyHead = new Node(0);
        Node* tail = dummyHead;
        Node* temp1 = headRef;
        
        while(temp1 != nullptr){
            Node* temp2 = temp1->next;
            
            while(temp2 != nullptr && temp1->data == temp2->data){
                temp2 = temp2->next;
            }
            
            tail->next = temp1;
            
            if(tail == dummyHead) {
                tail->prev  = nullptr;
            }
            else {
                temp1->prev = tail;
            }
            
            tail = temp1;
            temp1 = temp2;
        }
        
        tail->next = nullptr;
        Node* newHead = dummyHead->next;
        delete dummyHead;
        
        return newHead;
    }
};

//! OR same code but shorter version 

class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr->next != nullptr) {
            if (curr->data == curr->next->data) {
                Node* duplicate = curr->next;
                
                // Re-link around the duplicate node
                curr->next = duplicate->next;
                if (duplicate->next != nullptr) {
                    duplicate->next->prev = curr;
                }
                
                delete duplicate; // Prevents memory leak
            } else {
                curr = curr->next; // Only advance when no duplicate was found
            }
        }

        return head;
    }
};