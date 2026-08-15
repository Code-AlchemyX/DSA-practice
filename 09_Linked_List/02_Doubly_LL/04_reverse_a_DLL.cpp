//! Brute force

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution
{
public:
    Node *reverse(Node *head)
    {
        stack<int> st;
        Node *temp = head;

        while (temp != nullptr)
        {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

//! Optimal approach 

/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* currnode = head;
        Node* prevnode = nullptr;
        
        while(currnode != nullptr){
            prevnode = currnode->prev;
            
            //swap(curr->next , curr->back); OR
            
            currnode->prev = currnode->next;
            currnode->next = prevnode;
            
            //! dry run is must to understand this step
            currnode = currnode->prev;
        }
        
        return prevnode->prev;
    }
};