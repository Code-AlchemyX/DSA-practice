/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node *insertAtFront(Node *head, int x) {
        // Create a new node with value x.
        Node *newNode = new Node(x);
        
        // Point to the node's next pointer to the current head.
        newNode -> next = head;
        
        return newNode;
    }
};