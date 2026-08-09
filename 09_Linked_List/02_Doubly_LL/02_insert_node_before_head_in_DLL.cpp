/**
class Node
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      Node(int x, Node *prev, Node *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    Node* insertBeforeHead(Node* head, int x) {
        Node* newHead = new Node(x,nullptr,head);

        if(head != nullptr){
            head->prev = newHead;
        }

        return newHead;
    }
};