//! Easy solution --> striver's lec

/* Structure of doubly linked list Node
class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
    public:
    Node* deleteHead(Node* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr){
            delete head;
            return nullptr;
        }
        
        Node* prevHead = head;
        head = head->next;
        head->prev = nullptr;
        prevHead->next = nullptr;
        delete prevHead;
        
        return head;
    }
};

//! ====================================================================================

//! A bit confusing solution for newbies.

/* Structure of doubly linked list Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteHead(Node* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr){
            delete head;
            return nullptr;
        }
        
        Node* newHead = head->next;
        
        newHead->prev = nullptr;
        
        delete head;
        
        return newHead;
    }
};
