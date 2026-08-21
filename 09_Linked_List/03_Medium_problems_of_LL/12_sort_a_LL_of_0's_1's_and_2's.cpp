//! Brute Force

Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == 0) cnt0++;
        else if (temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
        if (cnt0 > 0) {
            temp->data = 0;
            cnt0--;
        } else if (cnt1 > 0) {
            temp->data = 1;
            cnt1--;
        } else {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }

    return head;
}



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

