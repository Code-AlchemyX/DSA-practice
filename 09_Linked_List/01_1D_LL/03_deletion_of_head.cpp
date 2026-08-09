/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node *deleteHead(Node *head) {
        if(head == NULL) return NULL;
        
        Node *newHead = head->next;
        
        head->next = NULL;
        delete head;
        
        return newHead;
    }
};
