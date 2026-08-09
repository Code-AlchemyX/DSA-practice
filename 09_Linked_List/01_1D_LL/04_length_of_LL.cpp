/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        int length = 1;
        Node *curr = head->next;
        
        while(curr != nullptr){
            length++;
            curr = curr->next;
        }
        return length;
    }
};