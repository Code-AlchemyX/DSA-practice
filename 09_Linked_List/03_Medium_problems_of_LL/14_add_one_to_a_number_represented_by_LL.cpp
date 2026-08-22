//! Brute force 

/* Structure of linked list Node
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
    Node* addOne(Node* head) {
        string num = "";
        Node* temp = head;
        while (temp != nullptr) {
            num += to_string(temp->data);
            temp = temp->next;
        }

        int carry = 1;
        for (int i = num.length() - 1; i >= 0; i--) {
            int sum = (num[i] - '0') + carry;
            num[i] = (sum % 10) + '0';
            carry = sum / 10;
            if (carry == 0) break;
        }

        if (carry > 0) {
            num = "1" + num;
        }

        Node* dummy = new Node(0);
        Node* curr = dummy;
        for (char c : num) {
            curr->next = new Node(c - '0');
            curr = curr->next;
        }

        return dummy->next;
    }
};

//! Better approach 

/* Structure of linked list Node
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
  
    Node* reverseList(Node* head) {
        Node* currnode = head;
        Node* prevnode = nullptr;

        while (currnode != nullptr) {
            Node* nextnode = currnode->next;
            currnode->next = prevnode;
            prevnode = currnode;
            currnode = nextnode;
        }

        return prevnode;
    }
    

    Node* addOne(Node* head) {
        //Reverse the LL
        head = reverseList(head);
        
        //Now add 1 to the reversed LL
        int carry = 1;
        Node* temp = head;
        
        while(temp != nullptr){
            int sum = temp->data + carry;
            
            if(sum == 10){
                temp->data = 0;
                carry = 1;
            
                if(temp->next == nullptr){
                    temp->next = new Node(1);
                    break;
                }
            } 
            else {
                temp->data = sum;
                carry = 0;
                break;
            }
            
            temp = temp->next;
        }
        
        return  reverseList(head);
    }
};


//! Optimal approach 

