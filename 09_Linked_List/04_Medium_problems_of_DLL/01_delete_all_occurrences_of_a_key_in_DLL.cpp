/* a Node of the doubly linked list
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
    Node * deleteAllOccurOfX ( Node * head , int x ) {
        if ( head == nullptr ) return head ;
        
        Node * temp = head ;
        
        while ( temp != nullptr ) {
            Node * nextNode = temp -> next ;
            
            if ( temp -> data == x ) {
                if (temp == head) head = temp -> next ;
                if (temp -> prev != nullptr) temp -> prev -> next = temp -> next ;
                if (temp -> next != nullptr) temp -> next -> prev = temp -> prev ;
                delete temp ;
            }
            temp = nextNode ;
        }
        
        return head ;
    }
};