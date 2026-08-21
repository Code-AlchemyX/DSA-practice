//! Optimal 1 --> Self derived

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head) return nullptr;
        
        Node* temp = head;
        
        Node* checkZero = head;
        while(checkZero != nullptr && temp != nullptr){
            if(checkZero->data == 0){
                swap(temp->data , checkZero->data);
                temp = temp->next;
            }
            checkZero = checkZero->next;
        }
        
        
        Node* checkOne = temp;
        while(checkOne != nullptr && temp != nullptr){
            if(checkOne->data == 1){
                swap(temp->data , checkOne->data);
                temp = temp->next;
            }
            checkOne = checkOne->next;
        }
        
        return head;
    }
};


//! Optimal 2 

