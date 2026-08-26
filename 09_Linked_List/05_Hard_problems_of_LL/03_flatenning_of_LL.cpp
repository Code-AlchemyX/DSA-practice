//! Brute Force 

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  public:
    Node* convertIntoLL(Node* head) {
        //temp1 = the pointer that moves below.(iterates through each LL)
        //temp2 = the pointer that moves sideways.(iterates through heads of LL)
        
        Node* temp1 = head;

        while (temp1 != nullptr) {
            Node* nextHead = temp1->next;
            Node* temp2 = temp1;

            while (temp2->bottom != nullptr) {
                temp2 = temp2->bottom;
            }

            temp2->bottom = nextHead;
            temp1->next = nullptr;
            temp1 = nextHead;
        }

        return head;
    }

    Node* merge(Node* a, Node* b) {
        if (a == nullptr)
            return b;

        if (b == nullptr)
            return a;

        Node* result;

        if (a->data <= b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        }
        else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        return result;
    }

    Node* mergeSort(Node* head) {
        if (head == nullptr || head->bottom == nullptr)
            return head;

        Node* slow = head;
        Node* fast = head;

        while (fast->bottom != nullptr &&
               fast->bottom->bottom != nullptr) {
            slow = slow->bottom;
            fast = fast->bottom->bottom;
        }

        Node* second = slow->bottom;
        slow->bottom = nullptr;

        Node* first = mergeSort(head);
        second = mergeSort(second);

        return merge(first, second);
    }
    
    Node* flatten(Node* head) {
        //Convert 2D structure into 1D Linked List
        head = convertIntoLL(head);

        //Pass to your Merge Sort function (or return sorted head)
        return mergeSort(head); 
    }
};


//! Optimal Approach

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/
class Solution {
public:
    Node* merge(Node* a, Node* b) {
        Node dummy(0);
        Node* t = &dummy;

        while(a && b) {
            if(a->data <= b->data) {
                t->bottom = a;
                a = a->bottom;
            } else {
                t->bottom = b;
                b = b->bottom;
            }
            t = t->bottom;
        }

        t->bottom = a ? a : b;

        return dummy.bottom;
    }

    Node* flatten(Node* head) {
        if(!head || !head->next)
            return head;

        head->next = flatten(head->next);

        return merge(head, head->next);
    }
};